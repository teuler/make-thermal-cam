/*
 * This file is part of the micropython-ulab project,
 *
 * https://github.com/v923z/micropython-ulab
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Zoltán Vörös
*/

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "py/obj.h"
#include "py/runtime.h"
#include "py/misc.h"
#include "user.h"

#if ULAB_HAS_USER_MODULE

//| """This module should hold arbitrary user-defined functions."""
//|

static mp_obj_t user_dummy(mp_obj_t arg_obj) {
    if(!mp_obj_is_type(arg_obj, &ulab_ndarray_type)) {
        mp_raise_TypeError(translate("`dummy` requires an ndarray"));
    }
    ndarray_obj_t *arg_arr = MP_OBJ_TO_PTR(arg_obj);
    mp_float_t *arg_items = (mp_float_t *)arg_arr->array;
    mp_float_t sum, mean, sd;
    sum = 0;
    for(size_t i=0; i<arg_arr->len; i++) {
	        sum += arg_items[i];
    }
    mean = (mp_float_t)sum /arg_arr->len;
    sum = 0;
    for(size_t i=0; i<arg_arr->len; i++) {
        sum += (mp_float_t)pow(arg_items[i] -mean, 2);
    }
    sd = (mp_float_t)sqrt(sum /arg_arr->len);
    mp_obj_t tempL = mp_obj_new_list(0, NULL);
    mp_obj_list_append(tempL, mp_obj_new_float(mean));
    mp_obj_list_append(tempL, mp_obj_new_float(sd));
    return tempL;
}

MP_DEFINE_CONST_FUN_OBJ_1(user_dummy_obj, user_dummy);

static const mp_rom_map_elem_t ulab_user_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_user) },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_dummy), (mp_obj_t)&user_dummy_obj },
};

static MP_DEFINE_CONST_DICT(mp_module_ulab_user_globals, ulab_user_globals_table);

mp_obj_module_t ulab_user_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_ulab_user_globals,
};

#endif
