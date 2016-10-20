//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

#pragma once

#include "./Reference.h"
#include "./Metadata.h"
namespace pafcore{ class Type; }

namespace pafcore
{

	class PAFCORE_EXPORT StaticField : public Metadata
	{
	public:
		static ::pafcore::ClassType* GetType();
		virtual ::pafcore::ClassType* getType();
		virtual size_t getAddress();

		Type* get_type();
		size_t get_address() const;
		bool get_isConstant() const;
		bool get_isArray() const;
		bool get_isPointer() const;

	public:
		StaticField(const char* name, Type* type, size_t address, size_t arraySize, bool constant, TypeCompound tc);
	public:
		bool isArray()
		{
			return tc_array == m_typeCompound;
		}
		bool isPointer()
		{
			return tc_pointer == m_typeCompound;
		}
		bool isConstant()
		{
			return m_constant;
		}
	public:
		Type* m_type;
		size_t m_address;
		size_t m_arraySize;
		bool m_constant;
		byte_t m_typeCompound;

	};

}