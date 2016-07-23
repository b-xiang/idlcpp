//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

#pragma once

#include "./Typedef.mh"
#include "./Reference.mh"
#include "./Metadata.mh"
#include "./Type.mh"
#include "StaticField.mh"
#include "AutoRun.h"
#include "NameSpace.h"
#include "Result.h"
#include "Argument.h"
#include "InstanceField.h"
#include "StaticField.h"
#include "InstanceProperty.h"
#include "StaticProperty.h"
#include "InstanceMethod.h"
#include "StaticMethod.h"
#include "Enumerator.h"
#include "PrimitiveType.h"
#include "VoidType.h"


namespace idlcpp
{

	__pafcore__StaticField_Type::__pafcore__StaticField_Type() : ::pafcore::ClassType("StaticField", ::pafcore::static_field)
	{
		m_size = sizeof(::pafcore::StaticField);
		static BaseClass s_baseClasses[] =
		{
			{RuntimeTypeOf<::pafcore::Metadata>::RuntimeType::GetSingleton(), paf_base_offset_of(::pafcore::StaticField, ::pafcore::Metadata)},
		};
		m_baseClasses = s_baseClasses;
		m_baseClassCount = paf_array_size_of(s_baseClasses);
		static ::pafcore::InstanceProperty s_properties[] = 
		{
			::pafcore::InstanceProperty("address", GetSingleton(), StaticField_get_address, RuntimeTypeOf<::size_t>::RuntimeType::GetSingleton(), ::pafcore::Metadata::by_value, false, 0, 0, ::pafcore::Metadata::by_value, false),
			::pafcore::InstanceProperty("isArray", GetSingleton(), StaticField_get_isArray, RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), ::pafcore::Metadata::by_value, false, 0, 0, ::pafcore::Metadata::by_value, false),
			::pafcore::InstanceProperty("isConstant", GetSingleton(), StaticField_get_isConstant, RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), ::pafcore::Metadata::by_value, false, 0, 0, ::pafcore::Metadata::by_value, false),
			::pafcore::InstanceProperty("isPointer", GetSingleton(), StaticField_get_isPointer, RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), ::pafcore::Metadata::by_value, false, 0, 0, ::pafcore::Metadata::by_value, false),
			::pafcore::InstanceProperty("type", GetSingleton(), StaticField_get_type, RuntimeTypeOf<::pafcore::Type>::RuntimeType::GetSingleton(), ::pafcore::Metadata::by_ptr, false, 0, 0, ::pafcore::Metadata::by_value, false),
		};
		m_properties = s_properties;
		m_propertyCount = paf_array_size_of(s_properties);
		static Metadata* s_members[] = 
		{
			&s_properties[0],
			&s_properties[1],
			&s_properties[2],
			&s_properties[3],
			&s_properties[4],
		};
		m_members = s_members;
		m_memberCount = paf_array_size_of(s_members);
		::pafcore::NameSpace::GetGlobalNameSpace()->getNameSpace("pafcore")->registerMember(this);
	}

	void __pafcore__StaticField_Type::destroyInstance(void* address)
	{
		reinterpret_cast<::pafcore::Reference*>(address)->release();
	}

	void __pafcore__StaticField_Type::destroyArray(void* address)
	{
		paf_delete_array(reinterpret_cast<::pafcore::RefCountObject<::pafcore::StaticField>*>(address));
	}

	void __pafcore__StaticField_Type::assign(void* dst, const void* src)
	{
		*(::pafcore::StaticField*)dst = *(const ::pafcore::StaticField*)src;
	}

	::pafcore::ErrorCode __pafcore__StaticField_Type::StaticField_get_address(::pafcore::Variant* that, ::pafcore::Variant* value)
	{
		::pafcore::StaticField* self;
		if(!that->castToReferencePtr(GetSingleton(), (void**)&self))
		{
			return ::pafcore::e_invalid_this_type;
		}
		::size_t res = self->get_address();
		value->assignPrimitive(RuntimeTypeOf<::size_t>::RuntimeType::GetSingleton(), &res);
		return ::pafcore::s_ok;
	}

	::pafcore::ErrorCode __pafcore__StaticField_Type::StaticField_get_isArray(::pafcore::Variant* that, ::pafcore::Variant* value)
	{
		::pafcore::StaticField* self;
		if(!that->castToReferencePtr(GetSingleton(), (void**)&self))
		{
			return ::pafcore::e_invalid_this_type;
		}
		bool res = self->get_isArray();
		value->assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &res);
		return ::pafcore::s_ok;
	}

	::pafcore::ErrorCode __pafcore__StaticField_Type::StaticField_get_isConstant(::pafcore::Variant* that, ::pafcore::Variant* value)
	{
		::pafcore::StaticField* self;
		if(!that->castToReferencePtr(GetSingleton(), (void**)&self))
		{
			return ::pafcore::e_invalid_this_type;
		}
		bool res = self->get_isConstant();
		value->assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &res);
		return ::pafcore::s_ok;
	}

	::pafcore::ErrorCode __pafcore__StaticField_Type::StaticField_get_isPointer(::pafcore::Variant* that, ::pafcore::Variant* value)
	{
		::pafcore::StaticField* self;
		if(!that->castToReferencePtr(GetSingleton(), (void**)&self))
		{
			return ::pafcore::e_invalid_this_type;
		}
		bool res = self->get_isPointer();
		value->assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &res);
		return ::pafcore::s_ok;
	}

	::pafcore::ErrorCode __pafcore__StaticField_Type::StaticField_get_type(::pafcore::Variant* that, ::pafcore::Variant* value)
	{
		::pafcore::StaticField* self;
		if(!that->castToReferencePtr(GetSingleton(), (void**)&self))
		{
			return ::pafcore::e_invalid_this_type;
		}
		::pafcore::Type* res = self->get_type();
		value->assignReferencePtr(RuntimeTypeOf<::pafcore::Type>::RuntimeType::GetSingleton(), res, false, ::pafcore::Variant::by_ptr);
		return ::pafcore::s_ok;
	}

	__pafcore__StaticField_Type* __pafcore__StaticField_Type::GetSingleton()
	{
		static __pafcore__StaticField_Type* s_instance = 0;
		static char s_buffer[sizeof(__pafcore__StaticField_Type)];
		if(0 == s_instance)
		{
			s_instance = (__pafcore__StaticField_Type*)s_buffer;
			new (s_buffer)__pafcore__StaticField_Type;
		}
		return s_instance;
	}

}

AUTO_REGISTER_TYPE(::idlcpp::__pafcore__StaticField_Type)
