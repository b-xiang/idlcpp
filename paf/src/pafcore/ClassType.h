//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

#pragma once

#include "./Type.h"
#include "./Typedef.h"
namespace pafcore{ class Metadata; }

namespace pafcore
{

	class InstanceField;
	class InstanceProperty;
	class InstanceMethod;
	class StaticField;
	class StaticProperty;
	class StaticMethod;
	class Enumerator;
	class SubclassInvoker;
	
	class PAFCORE_EXPORT ClassType : public Type
	{
	public:
		virtual ::pafcore::Type* getType();
		virtual size_t getAddress();

		::size_t _getMemberCount_(bool includeBaseClasses);
		Metadata* _getMember_(::size_t index,bool includeBaseClasses);
		Metadata* _findMember_(const char* name,bool includeBaseClasses);
		::size_t _getBaseClassCount_();
		Metadata* _getBaseClass_(::size_t index);

	public:
		struct BaseClass
		{
			ClassType* m_type;
			ptrdiff_t m_offset;
		};
	public:
		ClassType(const char* name, Category category);
	public:
		virtual Metadata* findMember(const char* name);
		virtual void* createSubclassProxy(SubclassInvoker* subclassInvoker);
		virtual void destroySubclassProxy(void* subclassProxy);
		Metadata* findMember(const char* name, bool includeBaseClasses);
		Metadata* findClassMember(const char* name, bool includeBaseClasses);
	public:
		bool getBaseClassOffset_(size_t& offset, ClassType* otherType);
		bool getBaseClassOffset(size_t& offset, ClassType* otherType);
		Type* findNestedType(const char* name, bool includeBaseClasses);
		InstanceField* findInstanceField(const char* name, bool includeBaseClasses);
		StaticField* findStaticField(const char* name, bool includeBaseClasses);
		InstanceProperty* findInstanceProperty(const char* name, bool includeBaseClasses);
		StaticProperty* findStaticProperty(const char* name, bool includeBaseClasses);
		InstanceMethod* findInstanceMethod(const char* name, bool includeBaseClasses);
		StaticMethod* findStaticMethod(const char* name, bool includeBaseClasses);

	public:
		Type** m_nestedTypes;
		size_t m_nestedTypeCount;
		BaseClass* m_baseClasses;
		size_t m_baseClassCount;
		Metadata** m_members;
		size_t m_memberCount;
		InstanceField* m_fields;
		size_t m_fieldCount;
		InstanceProperty* m_properties;
		size_t m_propertyCount;
		InstanceMethod* m_methods;
		size_t m_methodCount;
		StaticField* m_staticFields;
		size_t m_staticFieldCount;
		StaticProperty* m_staticProperties;
		size_t m_staticPropertyCount;
		StaticMethod* m_staticMethods;
		size_t m_staticMethodCount;
		
	};
}