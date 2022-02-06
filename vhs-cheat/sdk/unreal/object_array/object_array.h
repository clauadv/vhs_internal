#pragma once
#include "../name_pool/name_pool.h"

namespace sdk {
	struct u_object_array;
	struct u_class;

	struct u_object {
		static sdk::u_object_array* objects;
		void** vf_table;
		std::int32_t flags;
		std::int32_t internal_index;
		sdk::u_class* _class;
		sdk::u_name name;
		sdk::u_object* outer;

		std::string get_name() const;
		std::string get_full_name() const;
		bool is_a(void* cmp) const;
	};

	struct u_object_array {
		unsigned char** objects;
		unsigned char* pre_allocated_objects;
		std::uint32_t max_elements;
		std::uint32_t num_elements;
		std::uint32_t max_chunks;
		std::uint32_t num_chunks;

		sdk::u_object* get_object_ptr(std::uint32_t id) const;
		sdk::u_object* find_object(const char* name) const;
	};

	inline u_object_array* object_array;
}
