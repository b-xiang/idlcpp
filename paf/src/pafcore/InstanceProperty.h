//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

#pragma once

#include "./Metadata.h"
namespace pafcore{ class ClassType; }
namespace pafcore{ class Type; }

namespace pafcore
{


	struct Attributes;
	class InstanceProperty;
	class Iterator;
	class Variant;
	
	typedef ErrorCode(*InstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, Variant* value);
	typedef ErrorCode(*InstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, Variant* value);

	typedef ErrorCode(*ArrayInstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertySizer)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
	typedef ErrorCode(*ArrayInstancePropertyResizer)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
	
	typedef ErrorCode(*ListInstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ListInstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
 	typedef ErrorCode(*ListInstancePropertyPushBack)(InstanceProperty* instanceProperty, Variant* that, Variant* value);
	typedef ErrorCode(*ListInstancePropertyGetIterator)(InstanceProperty* instanceProperty, Variant* that, Variant* iterator);
	typedef ErrorCode(*ListInstancePropertyGetValue)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* value);

	typedef ErrorCode(*MapInstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, Variant* key, Variant* value);
	typedef ErrorCode(*MapInstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, Variant* key, Variant* value);
	typedef ErrorCode(*MapInstancePropertyGetIterator)(InstanceProperty* instanceProperty, Variant* that, Variant* iterator);
	typedef ErrorCode(*MapInstancePropertyGetKey)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* key);
	typedef ErrorCode(*MapInstancePropertyGetValue)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* value);



	class PAFCORE_EXPORT InstanceProperty : public Metadata
	{
	public:
		static ::pafcore::ClassType* GetType();
		virtual ::pafcore::ClassType* getType();
		virtual size_t getAddress();

		ClassType* get_objectType();

		bool get_isArray() const;
		bool get_isList() const;
		bool get_isMap() const;
		bool get_isSimple() const;

		bool get_hasGetter() const;
		bool get_hasSetter() const;
		bool get_hasSizer() const;
		bool get_hasResizer() const;

		Type* get_getterType();
		bool get_getterByValue() const;
		bool get_getterByRef() const;
		bool get_getterByPtr() const;
		bool get_getterConstant() const;

		Type* get_setterType();
		bool get_setterByValue() const;
		bool get_setterByRef() const;
		bool get_setterByPtr() const;
		bool get_setterConstant() const;

		Type* get_keyType();
		bool get_keyByValue() const;
		bool get_keyByRef() const;
		bool get_keyByPtr() const;
		bool get_keyConstant() const;


	public:
		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			InstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			InstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant);

		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			ArrayInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			ArrayInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			ArrayInstancePropertySizer sizer, 
			ArrayInstancePropertyResizer resizer);

		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			ListInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			ListInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			ListInstancePropertyPushBack pushBack,
			ListInstancePropertyGetIterator getIterator,
			ListInstancePropertyGetValue getValue);

		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			MapInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			MapInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			MapInstancePropertyGetIterator getIterator,
			MapInstancePropertyGetKey getKey,
			MapInstancePropertyGetValue getValue,
			Type* keyType, Passing keyPassing, bool keyConstant);
	public:
		ClassType * m_objectType;
		union
		{
			struct
			{
				InstancePropertyGetter m_getter;
				InstancePropertySetter m_setter;
			};
			struct
			{
				ArrayInstancePropertyGetter m_arrayGetter;
				ArrayInstancePropertySetter m_arraySetter;
				ArrayInstancePropertySizer m_arraySizer;
				ArrayInstancePropertyResizer m_arrayResizer;
			};
			struct
			{
				ListInstancePropertyGetter m_listGetter;
				ListInstancePropertySetter m_listSetter;
				ListInstancePropertyPushBack m_listPushBack;
				ListInstancePropertyGetIterator m_listGetIterator;
				ListInstancePropertyGetValue m_listGetValue;
			};
			struct
			{
				MapInstancePropertyGetter m_mapGetter;
				MapInstancePropertySetter m_mapSetter;
				MapInstancePropertyGetIterator m_mapGetIterator;
				MapInstancePropertyGetKey m_mapGetKey;
				MapInstancePropertyGetValue m_mapGetValue;
			};
		};
		Type* m_getterType;
		Type* m_setterType;
		Type* m_keyType;
		byte_t m_getterPassing;
		byte_t m_setterPassing;
		byte_t m_keyPassing;
		bool m_getterConstant;
		bool m_setterConstant;
		bool m_keyConstant;
		PropertyCategory m_category;

	};

}