#pragma once

#include "MemberNode.h"

struct GetterSetterNode;
struct TypeNameNode;

struct PropertyNode : MemberNode
{
	TokenNode* m_modifier;
	TypeNameNode* m_typeName;
	TokenNode* m_passing;//*
	GetterSetterNode* m_get;
	GetterSetterNode* m_set;
	PropertyCategory m_propertyCategory;
	TypeNameNode* m_keyTypeName;
	TokenNode* m_keyPassing;//*
public:
	PropertyNode(IdentifyNode* name, PropertyCategory category);
	PropertyCategory getCategory();
	bool isStatic();
	bool isSimple();
	bool isFixedArray();
	bool isDynamicArray();
	bool isList();
	bool isMap();

	bool isKeyByPtr();
	bool isKeyByValue();

	bool isByValue();
	bool isByPtr();

	void setGetter(GetterSetterNode* getter);
	void setSetter(GetterSetterNode* setter);
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};