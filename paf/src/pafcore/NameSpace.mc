//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

#pragma once

#include "./Metadata.mh"
#include "./Typedef.mh"
#include "NameSpace.mh"
#include "AutoRun.h"
#include "NameSpace.h"
#include "Result.h"
#include "Argument.h"
#include "InstanceField.h"
#include "StaticField.h"
#include "InstanceProperty.h"
#include "InstanceArrayProperty.h"
#include "StaticProperty.h"
#include "StaticArrayProperty.h"
#include "InstanceMethod.h"
#include "StaticMethod.h"
#include "Enumerator.h"
#include "PrimitiveType.h"
#include "VoidType.h"
#include "RefCountImpl.h"
#include <new>


namespace idlcpp
{

	__pafcore__NameSpace_Type::__pafcore__NameSpace_Type() : ::pafcore::ClassType("NameSpace", ::pafcore::name_space)
	{
		m_size = sizeof(::pafcore::NameSpace);
		static BaseClass s_baseClasses[] =
		{
			{RuntimeTypeOf<::pafcore::Metadata>::RuntimeType::GetSingleton(), paf_base_offset_of(::pafcore::NameSpace, ::pafcore::Metadata)},
		};
		m_baseClasses = s_baseClasses;
		m_baseClassCount = paf_array_size_of(s_baseClasses);
		static ::pafcore::ClassTypeIterator s_classTypeIterators[] =
		{
			::pafcore::ClassTypeIterator(RuntimeTypeOf<::pafcore::Metadata>::RuntimeType::GetSingleton()->m_firstDerivedClass, this),
		};
		RuntimeTypeOf<::pafcore::Metadata>::RuntimeType::GetSingleton()->m_firstDerivedClass = &s_classTypeIterators[0];
		m_classTypeIterators = s_classTypeIterators;
		static ::pafcore::Result s_instanceResults[] = 
		{
			::pafcore::Result(RuntimeTypeOf<::pafcore::Metadata>::RuntimeType::GetSingleton(), false, ::pafcore::Result::by_ptr),
			::pafcore::Result(RuntimeTypeOf<::size_t>::RuntimeType::GetSingleton(), false, ::pafcore::Result::by_value),
			::pafcore::Result(RuntimeTypeOf<::pafcore::Metadata>::RuntimeType::GetSingleton(), false, ::pafcore::Result::by_ptr),
		};
		static ::pafcore::Argument s_instanceArguments[] = 
		{
			::pafcore::Argument("name", RuntimeTypeOf<string_t>::RuntimeType::GetSingleton(), ::pafcore::Argument::by_value, false),
			::pafcore::Argument("index", RuntimeTypeOf<::size_t>::RuntimeType::GetSingleton(), ::pafcore::Argument::by_value, false),
		};
		static ::pafcore::Overload s_instanceOverloads[] = 
		{
			::pafcore::Overload(&s_instanceResults[0], &s_instanceArguments[0], 1, false, false),
			::pafcore::Overload(&s_instanceResults[1], 0, 0, false, false),
			::pafcore::Overload(&s_instanceResults[2], &s_instanceArguments[1], 1, false, false),
		};
		static ::pafcore::InstanceMethod s_instanceMethods[] = 
		{
			::pafcore::InstanceMethod("_findMember_", 0, NameSpace__findMember_, &s_instanceOverloads[0], 1),
			::pafcore::InstanceMethod("_getMemberCount_", 0, NameSpace__getMemberCount_, &s_instanceOverloads[1], 1),
			::pafcore::InstanceMethod("_getMember_", 0, NameSpace__getMember_, &s_instanceOverloads[2], 1),
		};
		m_instanceMethods = s_instanceMethods;
		m_instanceMethodCount = paf_array_size_of(s_instanceMethods);
		static Metadata* s_members[] = 
		{
			&s_instanceMethods[0],
			&s_instanceMethods[1],
			&s_instanceMethods[2],
		};
		m_members = s_members;
		m_memberCount = paf_array_size_of(s_members);
		::pafcore::NameSpace::GetGlobalNameSpace()->getNameSpace("pafcore")->registerMember(this);
	}

	void __pafcore__NameSpace_Type::destroyInstance(void* address)
	{
		reinterpret_cast<::pafcore::Reference*>(address)->release();
	}

	void __pafcore__NameSpace_Type::destroyArray(void* address)
	{
		paf_delete_array(reinterpret_cast<::pafcore::RefCountImpl<::pafcore::NameSpace>*>(address));
	}

	void __pafcore__NameSpace_Type::assign(void* dst, const void* src)
	{
		*(::pafcore::NameSpace*)dst = *(const ::pafcore::NameSpace*)src;
	}

	::pafcore::ErrorCode __pafcore__NameSpace_Type::NameSpace__findMember_(::pafcore::Variant* result, ::pafcore::Variant** args, int_t numArgs)
	{
		if(2 <= numArgs)
		{
			if(args[0]->isConstant())
			{
				return ::pafcore::e_this_is_constant;
			}
			::pafcore::NameSpace* self;
			if(!args[0]->castToReferencePtr(GetSingleton(), (void**)&self))
			{
				return ::pafcore::e_invalid_this_type;
			}
			string_t a0;
			if(!args[1]->castToPrimitive(RuntimeTypeOf<string_t>::RuntimeType::GetSingleton(), &a0))
			{
				return ::pafcore::e_invalid_arg_type_1;
			}
			::pafcore::Metadata* res = self->_findMember_(a0);
			result->assignReferencePtr(RuntimeTypeOf<::pafcore::Metadata>::RuntimeType::GetSingleton(), res, false, ::pafcore::Variant::by_ptr);
			return ::pafcore::s_ok;
		}
		return ::pafcore::e_invalid_arg_num;
	}

	::pafcore::ErrorCode __pafcore__NameSpace_Type::NameSpace__getMemberCount_(::pafcore::Variant* result, ::pafcore::Variant** args, int_t numArgs)
	{
		if(1 <= numArgs)
		{
			if(args[0]->isConstant())
			{
				return ::pafcore::e_this_is_constant;
			}
			::pafcore::NameSpace* self;
			if(!args[0]->castToReferencePtr(GetSingleton(), (void**)&self))
			{
				return ::pafcore::e_invalid_this_type;
			}
			::size_t res = self->_getMemberCount_();
			result->assignPrimitive(RuntimeTypeOf<::size_t>::RuntimeType::GetSingleton(), &res);
			return ::pafcore::s_ok;
		}
		return ::pafcore::e_invalid_arg_num;
	}

	::pafcore::ErrorCode __pafcore__NameSpace_Type::NameSpace__getMember_(::pafcore::Variant* result, ::pafcore::Variant** args, int_t numArgs)
	{
		if(2 <= numArgs)
		{
			if(args[0]->isConstant())
			{
				return ::pafcore::e_this_is_constant;
			}
			::pafcore::NameSpace* self;
			if(!args[0]->castToReferencePtr(GetSingleton(), (void**)&self))
			{
				return ::pafcore::e_invalid_this_type;
			}
			::size_t a0;
			if(!args[1]->castToPrimitive(RuntimeTypeOf<::size_t>::RuntimeType::GetSingleton(), &a0))
			{
				return ::pafcore::e_invalid_arg_type_1;
			}
			::pafcore::Metadata* res = self->_getMember_(a0);
			result->assignReferencePtr(RuntimeTypeOf<::pafcore::Metadata>::RuntimeType::GetSingleton(), res, false, ::pafcore::Variant::by_ptr);
			return ::pafcore::s_ok;
		}
		return ::pafcore::e_invalid_arg_num;
	}

	__pafcore__NameSpace_Type* __pafcore__NameSpace_Type::GetSingleton()
	{
		static __pafcore__NameSpace_Type* s_instance = 0;
		static char s_buffer[sizeof(__pafcore__NameSpace_Type)];
		if(0 == s_instance)
		{
			s_instance = (__pafcore__NameSpace_Type*)s_buffer;
			new (s_buffer)__pafcore__NameSpace_Type;
		}
		return s_instance;
	}

}

AUTO_REGISTER_TYPE(::idlcpp::__pafcore__NameSpace_Type)
