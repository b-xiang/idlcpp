//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

#pragma once

#include "./Typedef.mh"
#include "Reference.mh"
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

	__pafcore__Reference_Type::__pafcore__Reference_Type() : ::pafcore::ClassType("Reference", ::pafcore::reference_object)
	{
		m_size = sizeof(::pafcore::Reference);
		static ::pafcore::InstanceProperty s_properties[] = 
		{
			::pafcore::InstanceProperty("refCount", GetSingleton(), Reference_get_refCount, RuntimeTypeOf<::long_t>::RuntimeType::GetSingleton(), ::pafcore::Metadata::by_value, false, 0, 0, ::pafcore::Metadata::by_value, false),
		};
		m_properties = s_properties;
		m_propertyCount = array_size_of(s_properties);
		static Metadata* s_members[] = 
		{
			&s_properties[0],
		};
		m_members = s_members;
		m_memberCount = array_size_of(s_members);
		::pafcore::NameSpace::GetGlobalNameSpace()->getNameSpace("pafcore")->registerMember(this);
	}

	void __pafcore__Reference_Type::destroyInstance(void* address)
	{
		reinterpret_cast<::pafcore::Reference*>(address)->release();
	}

	void __pafcore__Reference_Type::destroyArray(void* address)
	{
		delete_array(reinterpret_cast<::pafcore::RefCountObject<::pafcore::Reference>*>(address));
	}

	void __pafcore__Reference_Type::assign(void* dst, const void* src)
	{
		*(::pafcore::Reference*)dst = *(const ::pafcore::Reference*)src;
	}

	::pafcore::ErrorCode __pafcore__Reference_Type::Reference_get_refCount(::pafcore::Variant* that, ::pafcore::Variant* value)
	{
		::pafcore::Reference* self;
		if(!that->castToReferencePtr(GetSingleton(), (void**)&self))
		{
			return ::pafcore::e_invalid_this_type;
		}
		::long_t res = self->get_refCount();
		value->assignPrimitive(RuntimeTypeOf<::long_t>::RuntimeType::GetSingleton(), &res);
		return ::pafcore::s_ok;
	}

	__pafcore__Reference_Type* __pafcore__Reference_Type::GetSingleton()
	{
		static __pafcore__Reference_Type* s_instance = 0;
		static char s_buffer[sizeof(__pafcore__Reference_Type)];
		if(0 == s_instance)
		{
			s_instance = (__pafcore__Reference_Type*)s_buffer;
			new (s_buffer)__pafcore__Reference_Type;
		}
		return s_instance;
	}

}

AUTO_REGISTER_TYPE(::idlcpp::__pafcore__Reference_Type)
