#include "ParameterNode.h"
#include "TypeNameNode.h"
#include "IdentifyNode.h"
#include "MethodNode.h"
#include "ClassNode.h"
#include "RaiseError.h"
#include "TypeTree.h"
#include "Compiler.h"
#include <assert.h>

ParameterNode::ParameterNode(TypeNameNode* typeName, TokenNode* out, TokenNode* passing, IdentifyNode* name)
{
	m_nodeType = snt_parameter;
	m_constant = 0;
	m_typeName = typeName;
	m_out = out;
	m_passing = passing;
	m_name = name;
	m_array = false;
	m_allowNull = false;
}

bool ParameterNode::isConstant()
{
	return (0 != m_constant && snt_keyword_const == m_constant->m_nodeType);
}

bool ParameterNode::byValue()
{
	return 0 == m_passing;
}

bool ParameterNode::byPtr()
{
	return (0 != m_passing && '*' == m_passing->m_nodeType);
}

bool ParameterNode::byRef()
{
	return (0 != m_passing && '&' == m_passing->m_nodeType);
}

bool ParameterNode::outNew()
{
	return (0 != m_out && '^' == m_out->m_nodeType);
}

bool ParameterNode::isArray()
{
	return m_array;
}

bool ParameterNode::isInput()
{
	return 0 == m_out;
}

bool ParameterNode::isOutput()
{
	return 0 != m_out;
}

bool ParameterNode::isAllowNull()
{
	return m_allowNull;
}

void ParameterNode::checkSemantic(TemplateArguments* templateArguments)
{
	TypeNode* typeNode = m_typeName->getTypeNode(templateArguments);
	if(0 == typeNode)
	{
		return;
	}
	if(void_type == typeNode->getTypeCategory(templateArguments))
	{ 
		if ((isInput() && !byPtr()) || (isOutput() && outNew()))
		{
			RaiseError_InvalidParameterType(this);
		}
	}
	else if (primitive_type == typeNode->getTypeCategory(templateArguments))
	{
		if (byRef() && !isConstant())
		{
			RaiseError_InvalidParameterType(this);
		}
	}

	g_compiler.useType(typeNode, templateArguments, byValue() ? tu_use_definition : tu_use_declaration, m_typeName);
}
