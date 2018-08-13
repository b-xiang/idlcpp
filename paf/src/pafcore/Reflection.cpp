#include "Reflection.h"
#include "Reflection.mh"
#include "Reflection.ic"
#include "Reflection.mc"
#include "Type.h"
#include "TypeAlias.h"
#include "NameSpace.h"
#include "String.mh"
#include <string>

BEGIN_PAFCORE


String Reflection::GetTypeFullName(Type* type)
{
	const char* localName = type->get__name_();
	size_t totalLength = strlen(localName) + 1;
	const char* scopeNames[64];
	size_t scopeCount = 0;

	Metadata* scope = type->m_enclosing;
	while (scope)
	{
		Metadata* nextScope = 0;
		Category category = scope->get__category_();
		if (name_space == category)
		{
			nextScope = static_cast<NameSpace*>(scope)->m_enclosing;
			if (NameSpace::GetGlobalNameSpace() == scope)
			{
				break;
			}
		}
		else
		{
			PAF_ASSERT(class_type == category);
			nextScope = static_cast<ClassType*>(scope)->m_enclosing;
		}
		const char* scopeName = scope->get__name_();
		scopeNames[scopeCount++] = scopeName;
		totalLength += strlen(scopeName) + 1;
		scope = nextScope;
	}
	std::string name;
	name.reserve(totalLength);
	for (size_t i = 0; i < scopeCount; ++i)
	{
		name.append(scopeNames[scopeCount - 1 - i]);
		name.append(".");
	}
	name.append(localName);
	return String(name.c_str());
}

String Reflection::GetTypeAliasFullName(TypeAlias* typeAlias)
{
	const char* localName = typeAlias->get__name_();
	size_t totalLength = strlen(localName) + 1;
	const char* scopeNames[64];
	size_t scopeCount = 0;

	Metadata* scope = typeAlias->m_enclosing;
	while (scope)
	{
		Metadata* nextScope = 0;
		Category category = scope->get__category_();
		if (name_space == category)
		{
			nextScope = static_cast<NameSpace*>(scope)->m_enclosing;
			if (NameSpace::GetGlobalNameSpace() == scope)
			{
				break;
			}
		}
		else
		{
			PAF_ASSERT(class_type == category);
			nextScope = static_cast<ClassType*>(scope)->m_enclosing;
		}
		const char* scopeName = scope->get__name_();
		scopeNames[scopeCount++] = scopeName;
		totalLength += strlen(scopeName) + 1;
		scope = nextScope;
	}
	std::string name;
	name.reserve(totalLength);
	for (size_t i = 0; i < scopeCount; ++i)
	{
		name.append(scopeNames[scopeCount - 1 - i]);
		name.append(".");
	}
	name.append(localName);
	return String(name.c_str());
}

Type* Reflection::GetTypeFromFullName(const char* fullName)
{
	std::string name;
	const char* nameBegin = fullName;
	Metadata* metadata = NameSpace::GetGlobalNameSpace();
	while (metadata && nameBegin)
	{
		const char* dot = strchr(nameBegin, '.');
		if (dot)
		{
			name.assign(nameBegin, dot);
			nameBegin = dot + 1;
		}
		else
		{
			name.assign(nameBegin);
			nameBegin = 0;
		}
		Category category = metadata->get__category_();
		if (name_space == category)
		{
			metadata = static_cast<NameSpace*>(metadata)->findMember(name.c_str());
		}
		else if (class_type == category)
		{
			metadata = static_cast<ClassType*>(metadata)->findNestedType(name.c_str(), true, true);
		}
		else
		{
			PAF_ASSERT(void_type == category || primitive_type == category || enum_type == category);
		}
	}
	if (metadata)
	{
		Category category = metadata->get__category_();
		if (name_space != category)
		{
			PAF_ASSERT(void_type == category || primitive_type == category || enum_type == category || class_type == category);
			return static_cast<Type*>(metadata);
		}
	}
	return 0;
}

String Reflection::PrimitiveToString(const Variant& value)
{
	String res;
	char buf[64];
	PAF_ASSERT(value.m_type->isPrimitive());
	PrimitiveType* primitiveType = static_cast<PrimitiveType*>(value.m_type);
	switch (primitiveType->m_typeCategory)
	{
	case bool_type:
		res.assign(*reinterpret_cast<const bool*>(value.m_pointer) ? "true" : "false");
		break;
	case char_type:
		sprintf_s(buf, "%d", *reinterpret_cast<const char*>(value.m_pointer));
		res.assign(buf);
		break;
	case signed_char_type:
		sprintf_s(buf, "%d", *reinterpret_cast<const signed char*>(value.m_pointer));
		res.assign(buf);
		break;
	case unsigned_char_type:
		sprintf_s(buf, "%d", *reinterpret_cast<const unsigned char*>(value.m_pointer));
		res.assign(buf);
		break;
	case wchar_type:
		sprintf_s(buf, "%d", *reinterpret_cast<const wchar_t*>(value.m_pointer));
		res.assign(buf);
		break;
	case short_type:
		sprintf_s(buf, "%d", *reinterpret_cast<const short*>(value.m_pointer));
		res.assign(buf);
		break;
	case unsigned_short_type:
		sprintf_s(buf, "%d", *reinterpret_cast<const unsigned short*>(value.m_pointer));
		res.assign(buf);
		break;
	case int_type:
		sprintf_s(buf, "%d", *reinterpret_cast<const int*>(value.m_pointer));
		res.assign(buf);
		break;
	case unsigned_int_type:
		sprintf_s(buf, "%u", *reinterpret_cast<const unsigned int*>(value.m_pointer));
		res.assign(buf);
		break;
	case long_type:
		sprintf_s(buf, "%ld", *reinterpret_cast<const long*>(value.m_pointer));
		res.assign(buf);
		break;
	case unsigned_long_type:
		sprintf_s(buf, "%lu", *reinterpret_cast<const unsigned long*>(value.m_pointer));
		res.assign(buf);
		break;
	case long_long_type:
		sprintf_s(buf, "%lld", *reinterpret_cast<const long long*>(value.m_pointer));
		res.assign(buf);
		break;
	case unsigned_long_long_type:
		sprintf_s(buf, "%llud", *reinterpret_cast<const unsigned long long*>(value.m_pointer));
		res.assign(buf);
		break;
	case float_type:
		sprintf_s(buf, "%.8g", *reinterpret_cast<const float*>(value.m_pointer));
		res.assign(buf);
		break;
	case double_type:
		sprintf_s(buf, "%.16g", *reinterpret_cast<const double*>(value.m_pointer));
		res.assign(buf);
		break;
	case long_double_type:
		sprintf_s(buf, "%.16g", *reinterpret_cast<const long double*>(value.m_pointer));
		res.assign(buf);
		break;
	}
	return res;
}

void Reflection::StringToPrimitive(Variant& value, PrimitiveType* primitiveType, const char* str)
{
	switch (primitiveType->m_typeCategory)
	{
	case bool_type:
	{
		bool val = (0 == strcmp(str, "true")) ? true : false;
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case char_type:
	{
		char val = atoi(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case signed_char_type:
	{
		signed char val = atoi(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case unsigned_char_type:
	{
		unsigned char val = atoi(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case wchar_type:
	{
		wchar_t val = atoi(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case short_type:
	{
		short val = atoi(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case unsigned_short_type:
	{
		unsigned short val = atoi(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case int_type:
	{
		int val = atoi(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case unsigned_int_type:
	{
		unsigned int val = atoi(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case long_type:
	{
		long val = atol(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case unsigned_long_type:
	{
		unsigned long val = atol(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case long_long_type:
	{
		long long val = _atoi64(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case unsigned_long_long_type:
	{
		unsigned long long val = _atoi64(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case float_type:
	{
		float val = (float)atof(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case double_type:
	{
		double val = atof(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	case long_double_type:
	{
		long double val = atof(str);
		value.assignPrimitive(primitiveType, &val);
	}
	break;
	}
}

String Reflection::EnumToString(const Variant& value)
{
	PAF_ASSERT(value.m_type->isEnum());
	EnumType* enumType = static_cast<EnumType*>(value.m_type);
	int enumValue = 0;
	value.castToEnum(enumType, &enumValue);
	Enumerator* enumerator = enumType->_getEnumeratorByValue_(enumValue);
	if (enumerator)
	{
		return String(enumerator->get__name_());
	}
	return String();
}

bool Reflection::StringToEnum(Variant& value, EnumType* enumType, const char* str)
{
	Enumerator* enumerator = enumType->findEnumerator(str);
	if (enumerator)
	{
		value.assignEnum(enumType, &enumerator->m_value);	
		return true;
	}
	return false;
}

String Reflection::ObjectToString(const Variant& value)
{
	PAF_ASSERT(value.m_type->isValue() || value.m_type->isReference());
	ClassType* classType = static_cast<ClassType*>(value.m_type);
	InstanceMethod* instanceMethod = classType->findInstanceMethod("toString", true);
	if (instanceMethod)
	{
		Variant result;
		Variant* args = (Variant*)&value;
		ErrorCode errorCode = (*instanceMethod->m_invoker)(&result, &args, 1);
		if (s_ok == errorCode && RuntimeTypeOf<String>::RuntimeType::GetSingleton() == result.m_type)
		{
			return *reinterpret_cast<String*>(result.m_pointer);
		}
	}
	return String();
}

bool Reflection::StringToObject(Variant& value, ClassType* classType, const char* str)
{
	StaticMethod* staticMethod = classType->findStaticMethod("FromString", true);
	if (staticMethod)
	{
		Variant arg;
		arg.assignPrimitivePtr(RuntimeTypeOf<char>::RuntimeType::GetSingleton(), str, true, Variant::by_ptr);
		Variant* args = &arg;
		ErrorCode errorCode = (*staticMethod->m_invoker)(&value, &args, 1);
		if (s_ok == errorCode)
		{
			return true;
		}
	}
	return false;
}

String Reflection::InstancePropertyToString(Reference* that, InstanceProperty* instanceProperty)
{
	pafcore::Variant varThat;
	varThat.assignReferencePtr(that->getType(), that, false, pafcore::Variant::by_ptr);
	return InstancePropertyToString(&varThat, instanceProperty);
}

String Reflection::InstancePropertyToString(Variant* that, InstanceProperty* instanceProperty)
{
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*instanceProperty->m_getter)(that, &value);
	if (pafcore::s_ok == errorCode)
	{
		if (value.m_type->isPrimitive())
		{
			return pafcore::Reflection::PrimitiveToString(value);
		}
		else if (value.m_type->isEnum())
		{
			return pafcore::Reflection::EnumToString(value);
		}
		else
		{
			PAF_ASSERT(value.m_type->isValue() || value.m_type->isReference());
			return pafcore::Reflection::ObjectToString(value);
		}
	}
	return pafcore::String();
}

ErrorCode Reflection::StringToInstanceProperty(Variant& that, InstanceProperty* instanceProperty, const char* str)
{
	if (0 == instanceProperty->m_setter)
	{
		return e_property_is_read_only;
	}
	pafcore::Variant value;
	if (instanceProperty->m_setterType->isPrimitive())
	{
		pafcore::Reflection::StringToPrimitive(value, static_cast<pafcore::PrimitiveType*>(instanceProperty->m_setterType), str);
	}
	else if (instanceProperty->m_setterType->isEnum())
	{
		pafcore::Reflection::StringToEnum(value, static_cast<pafcore::EnumType*>(instanceProperty->m_setterType), str);
	}
	else
	{
		PAF_ASSERT(instanceProperty->m_setterType->isValue() || instanceProperty->m_setterType->isReference());
		pafcore::Reflection::StringToObject(value, static_cast<pafcore::ClassType*>(instanceProperty->m_setterType), str);
	}
	pafcore::ErrorCode errorCode = (*instanceProperty->m_setter)(&that, &value);
	return errorCode;
}

ErrorCode Reflection::StringToInstanceProperty(Variant& that, const char* propertyName, const char* str)
{
	if (pafcore::class_type != that.m_type->get__category_())
	{
		return e_is_not_class;
	}
	pafcore::ClassType* classType = static_cast<pafcore::ClassType*>(that.m_type);
	pafcore::InstanceProperty* instanceProperty = classType->findInstanceProperty(propertyName, true);
	if (0 == instanceProperty)
	{
		return e_member_not_found;
	}
	return StringToInstanceProperty(that, instanceProperty, str);
}


ErrorCode Reflection::NewObject(Variant& result, ClassType* type)
{
	pafcore::StaticMethod* staticMethod = type->findStaticMethod("New", false);
	if (staticMethod)
	{
		pafcore::ErrorCode errorCode = (*staticMethod->m_invoker)(&result, 0, 0);
		return errorCode;
	}
	return e_member_not_found;
}
//
//ErrorCode Reflection::CallInstanceMethod(Variant& result, Reference* that, const char* methodName, Variant** args, int_t numArgs)
//{
//	ClassType* classType = that->getType();
//	InstanceMethod* instanceMethod = classType->findInstanceMethod(methodName, true);
//	if (0 == instanceMethod)
//	{
//		return e_member_not_found;
//	}
//
//	pafcore::ErrorCode errorCode = (*invoker)(&result, args, numArgs);
//	for (int i = 0; i < numArgs; i++)
//	{
//		pafcore::Variant* argument = (pafcore::Variant*)&argumentsBuf[sizeof(pafcore::Variant)*i];
//		argument->~Variant();
//	}
//
//	pafcore::Metadata* member;
//	member = variant->m_type->findMember(name);
//
//}

//ErrorCode Reflection::GetInstanceField(pafcore::Variant& value, pafcore::Variant* that, pafcore::InstanceField* field)
//{
//	size_t baseOffset;
//	if (!static_cast<pafcore::ClassType*>(that->m_type)->getClassOffset(baseOffset, field->m_objectType))
//	{
//		return pafcore::e_invalid_type;
//	}
//	size_t fieldAddress = (size_t)that->m_pointer + baseOffset + field->m_offset;
//
//	if (field->isArray())
//	{
//		value.assignArray(field->m_type, (void*)fieldAddress, field->m_arraySize, field->m_constant, ::pafcore::Variant::by_array);
//	}
//	else if (field->isPointer())
//	{
//		value.assignPtr(field->m_type, *(void**)fieldAddress, field->m_constant, ::pafcore::Variant::by_ref);
//	}
//	else
//	{
//		value.assignPtr(field->m_type, (void*)fieldAddress, field->m_type->isPrimitive() ? true : field->m_constant, ::pafcore::Variant::by_ref);
//	}
//	return pafcore::s_ok;
//}
//
//ErrorCode Reflection::SetInstanceField(pafcore::Variant* that, pafcore::InstanceField* field, pafcore::Variant& value)
//{
//	if (field->isArray())
//	{
//		return pafcore::e_field_is_an_array;
//	}
//	if (field->isConstant())
//	{
//		return pafcore::e_field_is_constant;
//	}
//	size_t baseOffset;
//	if (!static_cast<pafcore::ClassType*>(that->m_type)->getClassOffset(baseOffset, field->m_objectType))
//	{
//		return pafcore::e_invalid_object_type;
//	}
//	size_t fieldAddress = (size_t)that->m_pointer + baseOffset + field->m_offset;
//	if (field->isPointer())
//	{
//		if (!value.castToObjectPtr(field->m_type, (void**)fieldAddress))
//		{
//			return pafcore::e_invalid_field_type;
//		}
//	}
//	else
//	{
//		if (!value.castToObject(field->m_type, (void*)fieldAddress))
//		{
//			return pafcore::e_invalid_field_type;
//		}
//	}
//	return pafcore::s_ok;
//}


END_PAFCORE
