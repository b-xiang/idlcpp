//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

#pragma once

#include "./Reference.mh"
#include "Iterator.mh"
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
#include "RefCountImpl.h"
#include "Iterator.h"
#include <new>


namespace idlcpp
{

	__pafcore__Iterator_Type::__pafcore__Iterator_Type() : ::pafcore::ClassType("Iterator", ::pafcore::reference_object)
	{
		m_size = sizeof(::pafcore::Iterator);
		static BaseClass s_baseClasses[] =
		{
			{RuntimeTypeOf<::pafcore::Reference>::RuntimeType::GetSingleton(), paf_base_offset_of(::pafcore::Iterator, ::pafcore::Reference)},
		};
		m_baseClasses = s_baseClasses;
		m_baseClassCount = paf_array_size_of(s_baseClasses);
		static ::pafcore::ClassTypeIterator s_classTypeIterators[] =
		{
			::pafcore::ClassTypeIterator(RuntimeTypeOf<::pafcore::Reference>::RuntimeType::GetSingleton()->m_firstDerivedClass, this),
		};
		RuntimeTypeOf<::pafcore::Reference>::RuntimeType::GetSingleton()->m_firstDerivedClass = &s_classTypeIterators[0];
		m_classTypeIterators = s_classTypeIterators;
		static ::pafcore::Result s_instanceResults[] = 
		{
			::pafcore::Result(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), false, ::pafcore::Result::by_value),
			::pafcore::Result(RuntimeTypeOf<void>::RuntimeType::GetSingleton(), false, ::pafcore::Result::by_value),
			::pafcore::Result(RuntimeTypeOf<void>::RuntimeType::GetSingleton(), false, ::pafcore::Result::by_value),
		};
		static ::pafcore::Overload s_instanceOverloads[] = 
		{
			::pafcore::Overload(&s_instanceResults[0], 0, 0, false, false),
			::pafcore::Overload(&s_instanceResults[1], 0, 0, false, false),
			::pafcore::Overload(&s_instanceResults[2], 0, 0, false, false),
		};
		static ::pafcore::InstanceMethod s_instanceMethods[] = 
		{
			::pafcore::InstanceMethod("isEnd", 0, Iterator_isEnd, &s_instanceOverloads[0], 1),
			::pafcore::InstanceMethod("moveNext", 0, Iterator_moveNext, &s_instanceOverloads[1], 1),
			::pafcore::InstanceMethod("reset", 0, Iterator_reset, &s_instanceOverloads[2], 1),
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

	void __pafcore__Iterator_Type::destroyInstance(void* address)
	{
		reinterpret_cast<::pafcore::Reference*>(address)->release();
	}

	void __pafcore__Iterator_Type::destroyArray(void* address)
	{
		paf_delete_array(reinterpret_cast<::pafcore::RefCountImpl<::pafcore::Iterator>*>(address));
	}

	bool __pafcore__Iterator_Type::assign(void* dst, const void* src)
	{
		return false;
	}

	::pafcore::ErrorCode __pafcore__Iterator_Type::Iterator_isEnd(::pafcore::Variant* result, ::pafcore::Variant** args, int_t numArgs)
	{
		if(1 <= numArgs)
		{
			::pafcore::Iterator* self;
			if(!args[0]->castToReferencePtr(GetSingleton(), (void**)&self))
			{
				return ::pafcore::e_invalid_this_type;
			}
			bool res = self->isEnd();
			result->assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &res);
			return ::pafcore::s_ok;
		}
		return ::pafcore::e_invalid_arg_num;
	}

	::pafcore::ErrorCode __pafcore__Iterator_Type::Iterator_moveNext(::pafcore::Variant* result, ::pafcore::Variant** args, int_t numArgs)
	{
		if(1 <= numArgs)
		{
			::pafcore::Iterator* self;
			if(!args[0]->castToReferencePtr(GetSingleton(), (void**)&self))
			{
				return ::pafcore::e_invalid_this_type;
			}
			self->moveNext();
			return ::pafcore::s_ok;
		}
		return ::pafcore::e_invalid_arg_num;
	}

	::pafcore::ErrorCode __pafcore__Iterator_Type::Iterator_reset(::pafcore::Variant* result, ::pafcore::Variant** args, int_t numArgs)
	{
		if(1 <= numArgs)
		{
			::pafcore::Iterator* self;
			if(!args[0]->castToReferencePtr(GetSingleton(), (void**)&self))
			{
				return ::pafcore::e_invalid_this_type;
			}
			self->reset();
			return ::pafcore::s_ok;
		}
		return ::pafcore::e_invalid_arg_num;
	}

	__pafcore__Iterator_Type* __pafcore__Iterator_Type::GetSingleton()
	{
		static __pafcore__Iterator_Type* s_instance = 0;
		static char s_buffer[sizeof(__pafcore__Iterator_Type)];
		if(0 == s_instance)
		{
			s_instance = (__pafcore__Iterator_Type*)s_buffer;
			new (s_buffer)__pafcore__Iterator_Type;
		}
		return s_instance;
	}

}

AUTO_REGISTER_TYPE(::idlcpp::__pafcore__Iterator_Type)
