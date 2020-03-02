//
// Content for MICROPY_MODULE_FROZEN_STR
//
#include <stdint.h>
const char mp_frozen_str_names[] = {
"\0"};
const uint32_t mp_frozen_str_sizes[] = {
};
const char mp_frozen_str_content[] = {
};
//
// Content for MICROPY_MODULE_FROZEN_MPY
//
#include "py/mpconfig.h"
#include "py/objint.h"
#include "py/objstr.h"
#include "py/emitglue.h"
#include "py/nativeglue.h"

#if MICROPY_OPT_CACHE_MAP_LOOKUP_IN_BYTECODE != 0
#error "incompatible MICROPY_OPT_CACHE_MAP_LOOKUP_IN_BYTECODE"
#endif

#if MICROPY_LONGINT_IMPL != 2
#error "incompatible MICROPY_LONGINT_IMPL"
#endif

#if MPZ_DIG_SIZE != 16
#error "incompatible MPZ_DIG_SIZE"
#endif

#if MICROPY_PY_BUILTINS_FLOAT
typedef struct _mp_obj_float_t {
    mp_obj_base_t base;
    mp_float_t value;
} mp_obj_float_t;
#endif

#if MICROPY_PY_BUILTINS_COMPLEX
typedef struct _mp_obj_complex_t {
    mp_obj_base_t base;
    mp_float_t real;
    mp_float_t imag;
} mp_obj_complex_t;
#endif

enum {
    MP_QSTR_flashbdev_dot_py = MP_QSTRnumber_of,
    MP_QSTR_vfs,
    MP_QSTR_bdev,
    MP_QSTR_inisetup_dot_py,
    MP_QSTR_flashbdev,
    MP_QSTR_check_bootsec,
    MP_QSTR_fs_corrupted,
    MP_QSTR_setup,
    MP_QSTR_boot_dot_py,
    MP_QSTR_w,
    MP_QSTR__boot_dot_py,
    MP_QSTR_inisetup,
    MP_QSTR_apa106_dot_py,
    MP_QSTR_NeoPixel,
    MP_QSTR_neopixel,
    MP_QSTR_APA106,
    MP_QSTR_ORDER,
    MP_QSTR_neopixel_dot_py,
    MP_QSTR_n,
    MP_QSTR_bpp,
    MP_QSTR_buf,
    MP_QSTR_timing,
    MP_QSTR_val,
    MP_QSTR_color,
    MP_QSTR_upip_dot_py,
    MP_QSTR_os,
    MP_QSTR_json,
    MP_QSTR_upip_utarfile,
    MP_QSTR_tarfile,
    MP_QSTR_debug,
    MP_QSTR_index_urls,
    MP_QSTR_install_path,
    MP_QSTR_cleanup_files,
    MP_QSTR_gzdict_sz,
    MP_QSTR_file_buf,
    MP_QSTR_NotFoundError,
    MP_QSTR_op_split,
    MP_QSTR_op_basename,
    MP_QSTR__makedirs,
    MP_QSTR_save_file,
    MP_QSTR_install_tar,
    MP_QSTR_expandhome,
    MP_QSTR_warn_ussl,
    MP_QSTR_url_open,
    MP_QSTR_get_pkg_metadata,
    MP_QSTR_fatal,
    MP_QSTR_install_pkg,
    MP_QSTR_install,
    MP_QSTR_get_install_path,
    MP_QSTR_cleanup,
    MP_QSTR_fname,
    MP_QSTR_subf,
    MP_QSTR_setup_dot_,
    MP_QSTR_PKG_hyphen_INFO,
    MP_QSTR_README,
    MP_QSTR__dot_egg_hyphen_info,
    MP_QSTR_extractfile,
    MP_QSTR_deps,
    MP_QSTR_Skipping,
    MP_QSTR_DIRTYPE,
    MP_QSTR_f,
    MP_QSTR_prefix,
    MP_QSTR__tilde__slash_,
    MP_QSTR_getenv,
    MP_QSTR_HOME,
    MP_QSTR_s,
    MP_QSTR_https_colon_,
    MP_QSTR_url,
    MP_QSTR__percent_s_slash__percent_s_slash_json,
    MP_QSTR_Error_colon_,
    MP_QSTR_msg,
    MP_QSTR_exc,
    MP_QSTR_releases,
    MP_QSTR_TarFile,
    MP_QSTR_fileobj,
    MP_QSTR_pkg_spec,
    MP_QSTR_Queue_colon_,
    MP_QSTR_to_install,
    MP_QSTR_unlink,
    MP_QSTR__hyphen_h,
    MP_QSTR__hyphen__hyphen_help,
    MP_QSTR__hyphen_p,
    MP_QSTR__hyphen_r,
    MP_QSTR__hash_,
    MP_QSTR__hyphen_i,
    MP_QSTR__hyphen__hyphen_debug,
    MP_QSTR__hyphen_,
    MP_QSTR_upip_utarfile_dot_py,
    MP_QSTR_size,
    MP_QSTR_TAR_HEADER,
    MP_QSTR_REGTYPE,
    MP_QSTR_roundup,
    MP_QSTR_FileSection,
    MP_QSTR_TarInfo,
    MP_QSTR_align,
    MP_QSTR_skip,
    MP_QSTR_content_len,
    MP_QSTR_aligned_len,
    MP_QSTR_sz,
    MP_QSTR__0x00_,
    MP_QSTR_tarinfo,
    MP_QSTR_ntptime_dot_py,
    MP_QSTR_NTP_DELTA,
    MP_QSTR_host,
    MP_QSTR_settime,
    MP_QSTR__bang_I,
    MP_QSTR_dht_dot_py,
    MP_QSTR_pyb,
    MP_QSTR_DHTBase,
    MP_QSTR_DHT11,
    MP_QSTR_DHT22,
    MP_QSTR_measure,
    MP_QSTR_humidity,
    MP_QSTR_temperature,
    MP_QSTR_ds18x20_dot_py,
    MP_QSTR_DS18X20,
    MP_QSTR_convert_temp,
    MP_QSTR_read_scratch,
    MP_QSTR_write_scratch,
    MP_QSTR_read_temp,
    MP_QSTR_ow,
    MP_QSTR_SKIP_ROM,
    MP_QSTR_select_rom,
    MP_QSTR_CRC_space_error,
    MP_QSTR_rom,
    MP_QSTR_onewire_dot_py,
    MP_QSTR__ow,
    MP_QSTR_OneWireError,
    MP_QSTR_OneWire,
    MP_QSTR_SEARCH_ROM,
    MP_QSTR_MATCH_ROM,
    MP_QSTR__search_rom,
    MP_QSTR_required,
    MP_QSTR_l_rom,
    MP_QSTR_diff,
    MP_QSTR_data,
    MP_QSTR_webrepl_dot_py,
    MP_QSTR_websocket_helper,
    MP_QSTR_listen_s,
    MP_QSTR_client_s,
    MP_QSTR_setup_conn,
    MP_QSTR_accept_conn,
    MP_QSTR_start_foreground,
    MP_QSTR_0_dot_0_dot_0_dot_0,
    MP_QSTR_port,
    MP_QSTR_accept_handler,
    MP_QSTR_rejected,
    MP_QSTR_server_handshake,
    MP_QSTR_listen_sock,
    MP_QSTR_webrepl_cfg,
    MP_QSTR_PASS,
    MP_QSTR_webrepl_setup_dot_py,
    MP_QSTR__dot__slash_boot_dot_py,
    MP_QSTR_RC,
    MP_QSTR_CONFIG,
    MP_QSTR_input_choice,
    MP_QSTR_getpass,
    MP_QSTR_input_pass,
    MP_QSTR_exists,
    MP_QSTR_get_daemon_status,
    MP_QSTR_change_daemon,
    MP_QSTR_prompt,
    MP_QSTR_choices,
    MP_QSTR_webrepl,
    MP_QSTR__dot_tmp,
    MP_QSTR_action,
    MP_QSTR_enabled,
    MP_QSTR_disabled,
    MP_QSTR__gt__space_,
    MP_QSTR_E,
    MP_QSTR_y,
    MP_QSTR_PASS_space__equals__space__percent_r_0x0a_,
    MP_QSTR_D,
    MP_QSTR_websocket_helper_dot_py,
    MP_QSTR_binascii,
    MP_QSTR_hashlib,
    MP_QSTR_DEBUG,
    MP_QSTR_client_handshake,
    MP_QSTR_rwb,
    MP_QSTR_respkey_colon_,
    MP_QSTR__0x0d__0x0a__0x0d__0x0a_,
    MP_QSTR_sock,
};

extern const qstr_pool_t mp_qstr_const_pool;
const qstr_pool_t mp_qstr_frozen_const_pool = {
    (qstr_pool_t*)&mp_qstr_const_pool, // previous pool
    MP_QSTRnumber_of, // previous pool size
    10, // allocated entries
    182, // used entries
    {
        (const byte*)"\xe7\xe7\x0c" "flashbdev.py",
        (const byte*)"\x86\x7a\x03" "vfs",
        (const byte*)"\x70\x30\x04" "bdev",
        (const byte*)"\xab\x1b\x0b" "inisetup.py",
        (const byte*)"\xc0\xf5\x09" "flashbdev",
        (const byte*)"\xff\x70\x0d" "check_bootsec",
        (const byte*)"\xd3\x63\x0c" "fs_corrupted",
        (const byte*)"\xc2\x02\x05" "setup",
        (const byte*)"\x74\xb9\x07" "boot.py",
        (const byte*)"\xd2\xb5\x01" "w",
        (const byte*)"\xab\x3d\x08" "_boot.py",
        (const byte*)"\x0c\xb4\x08" "inisetup",
        (const byte*)"\xa5\xdf\x09" "apa106.py",
        (const byte*)"\x69\x83\x08" "NeoPixel",
        (const byte*)"\x69\xa0\x08" "neopixel",
        (const byte*)"\xa2\x4e\x06" "APA106",
        (const byte*)"\x4b\x69\x05" "ORDER",
        (const byte*)"\xae\xc1\x0b" "neopixel.py",
        (const byte*)"\xcb\xb5\x01" "n",
        (const byte*)"\xc7\x49\x03" "bpp",
        (const byte*)"\x74\x49\x03" "buf",
        (const byte*)"\x35\x23\x06" "timing",
        (const byte*)"\xfe\x7a\x03" "val",
        (const byte*)"\xd8\x06\x05" "color",
        (const byte*)"\x9e\xa2\x07" "upip.py",
        (const byte*)"\x79\x6f\x02" "os",
        (const byte*)"\xfd\xd1\x04" "json",
        (const byte*)"\x32\x80\x0d" "upip_utarfile",
        (const byte*)"\x24\xc0\x07" "tarfile",
        (const byte*)"\xd4\x55\x05" "debug",
        (const byte*)"\x7c\x79\x0a" "index_urls",
        (const byte*)"\x56\x0a\x0c" "install_path",
        (const byte*)"\x8f\x1f\x0d" "cleanup_files",
        (const byte*)"\x34\x14\x09" "gzdict_sz",
        (const byte*)"\xed\x15\x08" "file_buf",
        (const byte*)"\x9e\x1a\x0d" "NotFoundError",
        (const byte*)"\xd7\xb9\x08" "op_split",
        (const byte*)"\xb7\x56\x0b" "op_basename",
        (const byte*)"\xb4\xa9\x09" "_makedirs",
        (const byte*)"\xbd\xa0\x09" "save_file",
        (const byte*)"\x7c\xcb\x0b" "install_tar",
        (const byte*)"\x4c\x47\x0a" "expandhome",
        (const byte*)"\x49\xae\x09" "warn_ussl",
        (const byte*)"\xc5\xfa\x08" "url_open",
        (const byte*)"\xa2\x78\x10" "get_pkg_metadata",
        (const byte*)"\xdb\xd0\x05" "fatal",
        (const byte*)"\xa7\xb8\x0b" "install_pkg",
        (const byte*)"\x04\xdb\x07" "install",
        (const byte*)"\xdf\xf8\x10" "get_install_path",
        (const byte*)"\xc5\x2e\x07" "cleanup",
        (const byte*)"\xe4\x55\x05" "fname",
        (const byte*)"\x27\x31\x04" "subf",
        (const byte*)"\x2c\x5b\x06" "setup.",
        (const byte*)"\xfa\xaa\x08" "PKG-INFO",
        (const byte*)"\x5f\xeb\x06" "README",
        (const byte*)"\x2d\x61\x09" ".egg-info",
        (const byte*)"\xae\x9d\x0b" "extractfile",
        (const byte*)"\x87\xec\x04" "deps",
        (const byte*)"\x34\xd0\x08" "Skipping",
        (const byte*)"\x42\x17\x07" "DIRTYPE",
        (const byte*)"\xc3\xb5\x01" "f",
        (const byte*)"\x95\x3e\x06" "prefix",
        (const byte*)"\x14\x71\x02" "~/",
        (const byte*)"\xae\xfb\x06" "getenv",
        (const byte*)"\x6a\x76\x04" "HOME",
        (const byte*)"\xd6\xb5\x01" "s",
        (const byte*)"\x34\xf9\x06" "https:",
        (const byte*)"\x8e\x63\x03" "url",
        (const byte*)"\xdd\x3c\x0a" "%s/%s/json",
        (const byte*)"\x47\x4d\x06" "Error:",
        (const byte*)"\x7c\x46\x03" "msg",
        (const byte*)"\xdb\x24\x03" "exc",
        (const byte*)"\x1f\x8d\x08" "releases",
        (const byte*)"\x64\xfd\x07" "TarFile",
        (const byte*)"\x04\x4c\x07" "fileobj",
        (const byte*)"\x43\x9a\x08" "pkg_spec",
        (const byte*)"\x0e\x69\x06" "Queue:",
        (const byte*)"\x80\xf8\x0a" "to_install",
        (const byte*)"\xfe\x8f\x06" "unlink",
        (const byte*)"\xe0\x66\x02" "-h",
        (const byte*)"\x34\x6e\x06" "--help",
        (const byte*)"\xf8\x66\x02" "-p",
        (const byte*)"\xfa\x66\x02" "-r",
        (const byte*)"\x86\xb5\x01" "#",
        (const byte*)"\xe1\x66\x02" "-i",
        (const byte*)"\x34\x9b\x07" "--debug",
        (const byte*)"\x88\xb5\x01" "-",
        (const byte*)"\x55\x87\x10" "upip_utarfile.py",
        (const byte*)"\x20\xa5\x04" "size",
        (const byte*)"\x82\x45\x0a" "TAR_HEADER",
        (const byte*)"\xcd\xd1\x07" "REGTYPE",
        (const byte*)"\x82\x38\x07" "roundup",
        (const byte*)"\x0a\x55\x0b" "FileSection",
        (const byte*)"\x4c\x5c\x07" "TarInfo",
        (const byte*)"\xa8\xfb\x05" "align",
        (const byte*)"\x04\xaf\x04" "skip",
        (const byte*)"\x54\x75\x0b" "content_len",
        (const byte*)"\xb1\x45\x0b" "aligned_len",
        (const byte*)"\xec\x70\x02" "sz",
        (const byte*)"\xa5\xb5\x01" "\x00",
        (const byte*)"\x0c\x60\x07" "tarinfo",
        (const byte*)"\x5d\x41\x0a" "ntptime.py",
        (const byte*)"\xe8\xfb\x09" "NTP_DELTA",
        (const byte*)"\x25\x35\x04" "host",
        (const byte*)"\x12\x8c\x07" "settime",
        (const byte*)"\x4d\x66\x02" "!I",
        (const byte*)"\x5a\xdd\x06" "dht.py",
        (const byte*)"\xee\x71\x03" "pyb",
        (const byte*)"\x28\x6f\x07" "DHTBase",
        (const byte*)"\x5d\x80\x05" "DHT11",
        (const byte*)"\xfd\x80\x05" "DHT22",
        (const byte*)"\x1d\xae\x07" "measure",
        (const byte*)"\x7c\xaf\x08" "humidity",
        (const byte*)"\xe9\xde\x0b" "temperature",
        (const byte*)"\xa6\x68\x0a" "ds18x20.py",
        (const byte*)"\x01\xb3\x07" "DS18X20",
        (const byte*)"\x41\x3c\x0c" "convert_temp",
        (const byte*)"\x54\x8e\x0c" "read_scratch",
        (const byte*)"\x3b\x20\x0d" "write_scratch",
        (const byte*)"\xe4\x2e\x09" "read_temp",
        (const byte*)"\x7d\x6f\x02" "ow",
        (const byte*)"\xcb\x11\x08" "SKIP_ROM",
        (const byte*)"\xe2\x4f\x0a" "select_rom",
        (const byte*)"\x4f\xcf\x09" "CRC error",
        (const byte*)"\xb5\x8b\x03" "rom",
        (const byte*)"\x0f\xd8\x0a" "onewire.py",
        (const byte*)"\x82\x1f\x03" "_ow",
        (const byte*)"\x50\x5d\x0c" "OneWireError",
        (const byte*)"\x68\xd8\x07" "OneWire",
        (const byte*)"\xa4\x6f\x0a" "SEARCH_ROM",
        (const byte*)"\xb9\x51\x09" "MATCH_ROM",
        (const byte*)"\xfb\x7e\x0b" "_search_rom",
        (const byte*)"\x2c\x4c\x08" "required",
        (const byte*)"\x26\xa3\x05" "l_rom",
        (const byte*)"\xc8\xfc\x04" "diff",
        (const byte*)"\x15\xdc\x04" "data",
        (const byte*)"\x99\x4f\x0a" "webrepl.py",
        (const byte*)"\xa9\x14\x10" "websocket_helper",
        (const byte*)"\x00\xea\x08" "listen_s",
        (const byte*)"\xd0\x46\x08" "client_s",
        (const byte*)"\x71\xe8\x0a" "setup_conn",
        (const byte*)"\x56\xbe\x0b" "accept_conn",
        (const byte*)"\xa1\x7a\x10" "start_foreground",
        (const byte*)"\xcb\xfa\x07" "0.0.0.0",
        (const byte*)"\x5c\xd8\x04" "port",
        (const byte*)"\xc2\x8d\x0e" "accept_handler",
        (const byte*)"\x4b\x21\x08" "rejected",
        (const byte*)"\xc8\xc4\x10" "server_handshake",
        (const byte*)"\xc7\x7d\x0b" "listen_sock",
        (const byte*)"\x23\x03\x0b" "webrepl_cfg",
        (const byte*)"\xb4\xef\x04" "PASS",
        (const byte*)"\x01\xe8\x10" "webrepl_setup.py",
        (const byte*)"\x15\x6d\x09" "./boot.py",
        (const byte*)"\x94\x74\x02" "RC",
        (const byte*)"\x8f\xbe\x06" "CONFIG",
        (const byte*)"\xe7\x42\x0c" "input_choice",
        (const byte*)"\x42\xe4\x07" "getpass",
        (const byte*)"\x7d\xe7\x0a" "input_pass",
        (const byte*)"\x05\x65\x06" "exists",
        (const byte*)"\xeb\xc0\x11" "get_daemon_status",
        (const byte*)"\x50\xd3\x0d" "change_daemon",
        (const byte*)"\xe1\x9d\x06" "prompt",
        (const byte*)"\x9d\x98\x07" "choices",
        (const byte*)"\xfe\x61\x07" "webrepl",
        (const byte*)"\x22\x7c\x04" ".tmp",
        (const byte*)"\x5b\xeb\x06" "action",
        (const byte*)"\xe0\x9e\x07" "enabled",
        (const byte*)"\xd5\x48\x08" "disabled",
        (const byte*)"\xdb\x68\x02" "> ",
        (const byte*)"\xe0\xb5\x01" "E",
        (const byte*)"\xdc\xb5\x01" "y",
        (const byte*)"\x94\xfc\x0a" "\x50\x41\x53\x53\x20\x3d\x20\x25\x72\x0a",
        (const byte*)"\xe1\xb5\x01" "D",
        (const byte*)"\xee\xbd\x13" "websocket_helper.py",
        (const byte*)"\x91\x3c\x08" "binascii",
        (const byte*)"\x10\x6d\x07" "hashlib",
        (const byte*)"\x34\x6d\x05" "DEBUG",
        (const byte*)"\x94\x95\x10" "client_handshake",
        (const byte*)"\xa2\x88\x03" "rwb",
        (const byte*)"\xbc\xba\x08" "respkey:",
        (const byte*)"\xc5\x9c\x04" "\x0d\x0a\x0d\x0a",
        (const byte*)"\xd1\x9f\x04" "sock",
    },
};

// frozen bytecode for file flashbdev.py, scope flashbdev_<module>
STATIC const byte fun_data_flashbdev__lt_module_gt_[69] = {
    0x20, 0x0e,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_flashbdev_dot_py & 0xff, MP_QSTR_flashbdev_dot_py >> 8,
    0x50, 0x38, 0x00,
    0x80, 
    0x10, MP_QSTR_Partition & 0xff, MP_QSTR_Partition >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_esp32 & 0xff, MP_QSTR_esp32 >> 8, 
    0x1c, MP_QSTR_Partition & 0xff, MP_QSTR_Partition >> 8, 
    0x16, MP_QSTR_Partition & 0xff, MP_QSTR_Partition >> 8, 
    0x59, 
    0x11, MP_QSTR_Partition & 0xff, MP_QSTR_Partition >> 8, 
    0x14, MP_QSTR_find & 0xff, MP_QSTR_find >> 8, 
    0x11, MP_QSTR_Partition & 0xff, MP_QSTR_Partition >> 8, 
    0x13, MP_QSTR_TYPE_DATA & 0xff, MP_QSTR_TYPE_DATA >> 8, 
    0x10, MP_QSTR_label & 0xff, MP_QSTR_label >> 8, 
    0x10, MP_QSTR_vfs & 0xff, MP_QSTR_vfs >> 8, 
    0x36, 0x82, 0x01, 
    0x16, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x11, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x44, 0x08, 0x80, 
    0x11, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x80, 
    0x55, 
    0x42, 0x01, 0x80, 
    0x51, 
    0x16, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x51, 
    0x63, 
};
const mp_raw_code_t raw_code_flashbdev__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_flashbdev__lt_module_gt_,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 69,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_flashbdev_dot_py,
        .line_info = fun_data_flashbdev__lt_module_gt_ + 0,
        .opcodes = fun_data_flashbdev__lt_module_gt_ + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file inisetup.py, scope inisetup__lt_module_gt__check_bootsec
STATIC const byte fun_data_inisetup__lt_module_gt__check_bootsec[87] = {
    0x40, 0x20,
    MP_QSTR_check_bootsec & 0xff, MP_QSTR_check_bootsec >> 8,
    MP_QSTR_inisetup_dot_py & 0xff, MP_QSTR_inisetup_dot_py >> 8,
    0x60, 0x20, 0x30, 0x2b, 0x22, 0x26, 0x28, 0x22, 0x2a, 0x24, 0x22, 0x00,
    0x12, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0x12, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x14, MP_QSTR_ioctl & 0xff, MP_QSTR_ioctl >> 8, 
    0x85, 
    0x80, 
    0x36, 0x02, 
    0x34, 0x01, 
    0xc0, 
    0x12, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x14, MP_QSTR_readblocks & 0xff, MP_QSTR_readblocks >> 8, 
    0x80, 
    0xb0, 
    0x36, 0x02, 
    0x59, 
    0x52, 
    0xc1, 
    0xb0, 
    0x5f, 
    0x4b, 0x15, 0x00, 
    0xc2, 
    0xb2, 
    0x22, 0x81, 0x7f, 
    0xdc, 
    0x44, 0x09, 0x80, 
    0x50, 
    0xc1, 
    0x59, 
    0x59, 
    0x59, 
    0x59, 
    0x42, 0x03, 0x80, 
    0x42, 0xe8, 0x7f, 
    0xb1, 
    0x44, 0x02, 0x80, 
    0x52, 
    0x63, 
    0x12, MP_QSTR_fs_corrupted & 0xff, MP_QSTR_fs_corrupted >> 8, 
    0x34, 0x00, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_inisetup__lt_module_gt__check_bootsec = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_inisetup__lt_module_gt__check_bootsec,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 87,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_check_bootsec,
        .qstr_source_file = MP_QSTR_inisetup_dot_py,
        .line_info = fun_data_inisetup__lt_module_gt__check_bootsec + 0,
        .opcodes = fun_data_inisetup__lt_module_gt__check_bootsec + 18,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file inisetup.py, scope inisetup__lt_module_gt__fs_corrupted
STATIC const byte fun_data_inisetup__lt_module_gt__fs_corrupted[40] = {
    0x18, 0x16,
    MP_QSTR_fs_corrupted & 0xff, MP_QSTR_fs_corrupted >> 8,
    MP_QSTR_inisetup_dot_py & 0xff, MP_QSTR_inisetup_dot_py >> 8,
    0x80, 0x10, 0x26, 0x20, 0x68, 0x60, 0x00,
    0x80, 
    0x51, 
    0x1b, MP_QSTR_time & 0xff, MP_QSTR_time >> 8, 
    0xc0, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x00, 
    0x34, 0x01, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_sleep & 0xff, MP_QSTR_sleep >> 8, 
    0x83, 
    0x36, 0x01, 
    0x59, 
    0x42, 0xed, 0x7f, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_inisetup__lt_module_gt__fs_corrupted_0 = {{&mp_type_str}, 33619, 258, (const byte*)"\x46\x41\x54\x20\x66\x69\x6c\x65\x73\x79\x73\x74\x65\x6d\x20\x61\x70\x70\x65\x61\x72\x73\x20\x74\x6f\x20\x62\x65\x20\x63\x6f\x72\x72\x75\x70\x74\x65\x64\x2e\x20\x49\x66\x20\x79\x6f\x75\x20\x68\x61\x64\x20\x69\x6d\x70\x6f\x72\x74\x61\x6e\x74\x20\x64\x61\x74\x61\x20\x74\x68\x65\x72\x65\x2c\x20\x79\x6f\x75\x0a\x6d\x61\x79\x20\x77\x61\x6e\x74\x20\x74\x6f\x20\x6d\x61\x6b\x65\x20\x61\x20\x66\x6c\x61\x73\x68\x20\x73\x6e\x61\x70\x73\x68\x6f\x74\x20\x74\x6f\x20\x74\x72\x79\x20\x74\x6f\x20\x72\x65\x63\x6f\x76\x65\x72\x20\x69\x74\x2e\x20\x4f\x74\x68\x65\x72\x77\x69\x73\x65\x2c\x20\x70\x65\x72\x66\x6f\x72\x6d\x0a\x66\x61\x63\x74\x6f\x72\x79\x20\x72\x65\x70\x72\x6f\x67\x72\x61\x6d\x6d\x69\x6e\x67\x20\x6f\x66\x20\x4d\x69\x63\x72\x6f\x50\x79\x74\x68\x6f\x6e\x20\x66\x69\x72\x6d\x77\x61\x72\x65\x20\x28\x63\x6f\x6d\x70\x6c\x65\x74\x65\x6c\x79\x20\x65\x72\x61\x73\x65\x20\x66\x6c\x61\x73\x68\x2c\x20\x66\x6f\x6c\x6c\x6f\x77\x65\x64\x0a\x62\x79\x20\x66\x69\x72\x6d\x77\x61\x72\x65\x20\x70\x72\x6f\x67\x72\x61\x6d\x6d\x69\x6e\x67\x29\x2e\x0a"};
STATIC const mp_rom_obj_t const_table_data_inisetup__lt_module_gt__fs_corrupted[1] = {
    MP_ROM_PTR(&const_obj_inisetup__lt_module_gt__fs_corrupted_0),
};
STATIC const mp_raw_code_t raw_code_inisetup__lt_module_gt__fs_corrupted = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_inisetup__lt_module_gt__fs_corrupted,
    .const_table = (mp_uint_t*)const_table_data_inisetup__lt_module_gt__fs_corrupted,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 40,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_fs_corrupted,
        .qstr_source_file = MP_QSTR_inisetup_dot_py,
        .line_info = fun_data_inisetup__lt_module_gt__fs_corrupted + 0,
        .opcodes = fun_data_inisetup__lt_module_gt__fs_corrupted + 13,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file inisetup.py, scope inisetup__lt_module_gt__setup
STATIC const byte fun_data_inisetup__lt_module_gt__setup[100] = {
    0x34, 0x1e,
    MP_QSTR_setup & 0xff, MP_QSTR_setup >> 8,
    MP_QSTR_inisetup_dot_py & 0xff, MP_QSTR_inisetup_dot_py >> 8,
    0x80, 0x1b, 0x26, 0x28, 0x2f, 0x2c, 0x2d, 0x2f, 0x8c, 0x07, 0x00,
    0x12, MP_QSTR_check_bootsec & 0xff, MP_QSTR_check_bootsec >> 8, 
    0x34, 0x00, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x00, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x13, MP_QSTR_VfsFat & 0xff, MP_QSTR_VfsFat >> 8, 
    0x14, MP_QSTR_mkfs & 0xff, MP_QSTR_mkfs >> 8, 
    0x12, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x14, MP_QSTR_VfsFat & 0xff, MP_QSTR_VfsFat >> 8, 
    0x12, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x36, 0x01, 
    0xc0, 
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x14, MP_QSTR_mount & 0xff, MP_QSTR_mount >> 8, 
    0xb0, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0x36, 0x02, 
    0x59, 
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0x10, MP_QSTR_boot_dot_py & 0xff, MP_QSTR_boot_dot_py >> 8, 
    0x10, MP_QSTR_w & 0xff, MP_QSTR_w >> 8, 
    0x34, 0x02, 
    0x47, 0x0b, 0x00, 
    0xc1, 
    0xb1, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0x23, 0x01, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x5c, 
    0x5d, 
    0xb0, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_inisetup__lt_module_gt__setup_0 = {{&mp_type_str}, 7181, 24, (const byte*)"\x50\x65\x72\x66\x6f\x72\x6d\x69\x6e\x67\x20\x69\x6e\x69\x74\x69\x61\x6c\x20\x73\x65\x74\x75\x70"};
STATIC const mp_obj_str_t const_obj_inisetup__lt_module_gt__setup_1 = {{&mp_type_str}, 18582, 139, (const byte*)"\x23\x20\x54\x68\x69\x73\x20\x66\x69\x6c\x65\x20\x69\x73\x20\x65\x78\x65\x63\x75\x74\x65\x64\x20\x6f\x6e\x20\x65\x76\x65\x72\x79\x20\x62\x6f\x6f\x74\x20\x28\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x77\x61\x6b\x65\x2d\x62\x6f\x6f\x74\x20\x66\x72\x6f\x6d\x20\x64\x65\x65\x70\x73\x6c\x65\x65\x70\x29\x0a\x23\x69\x6d\x70\x6f\x72\x74\x20\x65\x73\x70\x0a\x23\x65\x73\x70\x2e\x6f\x73\x64\x65\x62\x75\x67\x28\x4e\x6f\x6e\x65\x29\x0a\x23\x69\x6d\x70\x6f\x72\x74\x20\x77\x65\x62\x72\x65\x70\x6c\x0a\x23\x77\x65\x62\x72\x65\x70\x6c\x2e\x73\x74\x61\x72\x74\x28\x29\x0a"};
STATIC const mp_rom_obj_t const_table_data_inisetup__lt_module_gt__setup[2] = {
    MP_ROM_PTR(&const_obj_inisetup__lt_module_gt__setup_0),
    MP_ROM_PTR(&const_obj_inisetup__lt_module_gt__setup_1),
};
STATIC const mp_raw_code_t raw_code_inisetup__lt_module_gt__setup = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_inisetup__lt_module_gt__setup,
    .const_table = (mp_uint_t*)const_table_data_inisetup__lt_module_gt__setup,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 100,
    .n_obj = 2,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_setup,
        .qstr_source_file = MP_QSTR_inisetup_dot_py,
        .line_info = fun_data_inisetup__lt_module_gt__setup + 0,
        .opcodes = fun_data_inisetup__lt_module_gt__setup + 17,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file inisetup.py, scope inisetup_<module>
STATIC const byte fun_data_inisetup__lt_module_gt_[54] = {
    0x08, 0x16,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_inisetup_dot_py & 0xff, MP_QSTR_inisetup_dot_py >> 8,
    0x28, 0x50, 0x85, 0x0c, 0x85, 0x0b, 0x00,
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x16, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x80, 
    0x10, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_flashbdev & 0xff, MP_QSTR_flashbdev >> 8, 
    0x1c, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x16, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x59, 
    0x32, 0x00, 
    0x16, MP_QSTR_check_bootsec & 0xff, MP_QSTR_check_bootsec >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_fs_corrupted & 0xff, MP_QSTR_fs_corrupted >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR_setup & 0xff, MP_QSTR_setup >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_inisetup__lt_module_gt_[3] = {
    MP_ROM_PTR(&raw_code_inisetup__lt_module_gt__check_bootsec),
    MP_ROM_PTR(&raw_code_inisetup__lt_module_gt__fs_corrupted),
    MP_ROM_PTR(&raw_code_inisetup__lt_module_gt__setup),
};
const mp_raw_code_t raw_code_inisetup__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_inisetup__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_inisetup__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 54,
    .n_obj = 0,
    .n_raw_code = 3,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_inisetup_dot_py,
        .line_info = fun_data_inisetup__lt_module_gt_ + 0,
        .opcodes = fun_data_inisetup__lt_module_gt_ + 13,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file _boot.py, scope _boot_<module>
STATIC const byte fun_data__boot__lt_module_gt_[117] = {
    0x2c, 0x1a,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR__boot_dot_py & 0xff, MP_QSTR__boot_dot_py >> 8,
    0x28, 0x28, 0x50, 0x23, 0x26, 0x5b, 0x28, 0x4f, 0x00,
    0x80, 
    0x51, 
    0x1b, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x16, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x16, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x80, 
    0x10, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_flashbdev & 0xff, MP_QSTR_flashbdev >> 8, 
    0x1c, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x16, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x59, 
    0x48, 0x18, 0x00, 
    0x11, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x44, 0x0f, 0x80, 
    0x11, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x14, MP_QSTR_mount & 0xff, MP_QSTR_mount >> 8, 
    0x11, MP_QSTR_bdev & 0xff, MP_QSTR_bdev >> 8, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0x36, 0x02, 
    0x59, 
    0x4a, 0x20, 0x00, 
    0x57, 
    0x11, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8, 
    0xdf, 
    0x44, 0x17, 0x80, 
    0x59, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_inisetup & 0xff, MP_QSTR_inisetup >> 8, 
    0x16, MP_QSTR_inisetup & 0xff, MP_QSTR_inisetup >> 8, 
    0x11, MP_QSTR_inisetup & 0xff, MP_QSTR_inisetup >> 8, 
    0x14, MP_QSTR_setup & 0xff, MP_QSTR_setup >> 8, 
    0x36, 0x00, 
    0x16, MP_QSTR_vfs & 0xff, MP_QSTR_vfs >> 8, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x11, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x14, MP_QSTR_collect & 0xff, MP_QSTR_collect >> 8, 
    0x36, 0x00, 
    0x59, 
    0x51, 
    0x63, 
};
const mp_raw_code_t raw_code__boot__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data__boot__lt_module_gt_,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 117,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR__boot_dot_py,
        .line_info = fun_data__boot__lt_module_gt_ + 0,
        .opcodes = fun_data__boot__lt_module_gt_ + 15,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file apa106.py, scope apa106__lt_module_gt__APA106
STATIC const byte fun_data_apa106__lt_module_gt__APA106[32] = {
    0x18, 0x0e,
    MP_QSTR_APA106 & 0xff, MP_QSTR_APA106 >> 8,
    MP_QSTR_apa106_dot_py & 0xff, MP_QSTR_apa106_dot_py >> 8,
    0x8c, 0x07, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_APA106 & 0xff, MP_QSTR_APA106 >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x80, 
    0x81, 
    0x82, 
    0x83, 
    0x2a, 0x04, 
    0x16, MP_QSTR_ORDER & 0xff, MP_QSTR_ORDER >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_apa106__lt_module_gt__APA106 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_apa106__lt_module_gt__APA106,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 32,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_APA106,
        .qstr_source_file = MP_QSTR_apa106_dot_py,
        .line_info = fun_data_apa106__lt_module_gt__APA106 + 0,
        .opcodes = fun_data_apa106__lt_module_gt__APA106 + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file apa106.py, scope apa106_<module>
STATIC const byte fun_data_apa106__lt_module_gt_[41] = {
    0x18, 0x0e,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_apa106_dot_py & 0xff, MP_QSTR_apa106_dot_py >> 8,
    0x60, 0x70, 0x00,
    0x80, 
    0x10, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_neopixel & 0xff, MP_QSTR_neopixel >> 8, 
    0x1c, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8, 
    0x16, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8, 
    0x59, 
    0x54, 
    0x32, 0x00, 
    0x10, MP_QSTR_APA106 & 0xff, MP_QSTR_APA106 >> 8, 
    0x11, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8, 
    0x34, 0x03, 
    0x16, MP_QSTR_APA106 & 0xff, MP_QSTR_APA106 >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_apa106__lt_module_gt_[1] = {
    MP_ROM_PTR(&raw_code_apa106__lt_module_gt__APA106),
};
const mp_raw_code_t raw_code_apa106__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_apa106__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_apa106__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 41,
    .n_obj = 0,
    .n_raw_code = 1,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_apa106_dot_py,
        .line_info = fun_data_apa106__lt_module_gt_ + 0,
        .opcodes = fun_data_apa106__lt_module_gt_ + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel___init__
STATIC const byte fun_data_neopixel__lt_module_gt__NeoPixel___init__[64] = {
    0xb9, 0x84, 0x01, 0x18,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x80, 0x0a, 0x25, 0x25, 0x25, 0x2c, 0x2e, 0x00,
    0xb1, 
    0xb0, 
    0x18, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0xb2, 
    0xb0, 
    0x18, MP_QSTR_n & 0xff, MP_QSTR_n >> 8, 
    0xb3, 
    0xb0, 
    0x18, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8, 
    0x12, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0xb2, 
    0xb3, 
    0xf4, 
    0x34, 0x01, 
    0xb0, 
    0x18, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0x14, MP_QSTR_init & 0xff, MP_QSTR_init >> 8, 
    0xb1, 
    0x13, MP_QSTR_OUT & 0xff, MP_QSTR_OUT >> 8, 
    0x36, 0x01, 
    0x59, 
    0xb4, 
    0xb0, 
    0x18, MP_QSTR_timing & 0xff, MP_QSTR_timing >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel___init__[5] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_pin),
    MP_ROM_QSTR(MP_QSTR_n),
    MP_ROM_QSTR(MP_QSTR_bpp),
    MP_ROM_QSTR(MP_QSTR_timing),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 5,
    .fun_data = fun_data_neopixel__lt_module_gt__NeoPixel___init__,
    .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel___init__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 64,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 5,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name = MP_QSTR___init__,
        .qstr_source_file = MP_QSTR_neopixel_dot_py,
        .line_info = fun_data_neopixel__lt_module_gt__NeoPixel___init__ + 0,
        .opcodes = fun_data_neopixel__lt_module_gt__NeoPixel___init__ + 16,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel___setitem__
STATIC const byte fun_data_neopixel__lt_module_gt__NeoPixel___setitem__[56] = {
    0x5b, 0x12,
    MP_QSTR___setitem__ & 0xff, MP_QSTR___setitem__ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x80, 0x12, 0x27, 0x2a, 0x00,
    0xb1, 
    0xb0, 
    0x13, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8, 
    0xf4, 
    0xc3, 
    0xb0, 
    0x13, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8, 
    0x80, 
    0x42, 0x14, 0x80, 
    0x57, 
    0xc4, 
    0xb2, 
    0xb4, 
    0x55, 
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0xb3, 
    0xb0, 
    0x13, MP_QSTR_ORDER & 0xff, MP_QSTR_ORDER >> 8, 
    0xb4, 
    0x55, 
    0xf2, 
    0x56, 
    0x81, 
    0xe5, 
    0x58, 
    0x5a, 
    0xd7, 
    0x43, 0xe6, 0x7f, 
    0x59, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel___setitem__[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_index),
    MP_ROM_QSTR(MP_QSTR_val),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel___setitem__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .fun_data = fun_data_neopixel__lt_module_gt__NeoPixel___setitem__,
    .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel___setitem__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 56,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___setitem__,
        .qstr_source_file = MP_QSTR_neopixel_dot_py,
        .line_info = fun_data_neopixel__lt_module_gt__NeoPixel___setitem__ + 0,
        .opcodes = fun_data_neopixel__lt_module_gt__NeoPixel___setitem__ + 11,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel___getitem___<genexpr>
STATIC const byte fun_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_[41] = {
    0xdb, 0x40, 0x0e,
    MP_QSTR__lt_genexpr_gt_ & 0xff, MP_QSTR__lt_genexpr_gt_ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x80, 0x18, 0x00,
    0x53, 
    0xb2, 
    0x53, 
    0x53, 
    0x4b, 0x16, 0x00, 
    0xc3, 
    0x25, 0x00, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x25, 0x01, 
    0x25, 0x00, 
    0x13, MP_QSTR_ORDER & 0xff, MP_QSTR_ORDER >> 8, 
    0xb3, 
    0x55, 
    0xf2, 
    0x55, 
    0x67, 
    0x59, 
    0x42, 0xe7, 0x7f, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_[3] = {
    MP_ROM_QSTR(MP_QSTR__star_),
    MP_ROM_QSTR(MP_QSTR__star_),
    MP_ROM_QSTR(MP_QSTR__star_),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x01,
    .n_pos_args = 3,
    .fun_data = fun_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_,
    .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 41,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_genexpr_gt_,
        .qstr_source_file = MP_QSTR_neopixel_dot_py,
        .line_info = fun_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_ + 0,
        .opcodes = fun_data_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_ + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel___getitem__
STATIC const byte fun_data_neopixel__lt_module_gt__NeoPixel___getitem__[47] = {
    0x32, 0x92, 0x01,
    MP_QSTR___getitem__ & 0xff, MP_QSTR___getitem__ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x80, 0x17, 0x29, 0x28, 0x00, 0x00, 0x02,
    0xb1, 
    0x25, 0x00, 
    0x13, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8, 
    0xf4, 
    0x27, 0x02, 
    0x12, MP_QSTR_tuple & 0xff, MP_QSTR_tuple >> 8, 
    0xb0, 
    0xb2, 
    0x20, 0x02, 0x02, 
    0x12, MP_QSTR_range & 0xff, MP_QSTR_range >> 8, 
    0x25, 0x00, 
    0x13, MP_QSTR_bpp & 0xff, MP_QSTR_bpp >> 8, 
    0x34, 0x01, 
    0x5e, 
    0x34, 0x01, 
    0x34, 0x01, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel___getitem__[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_index),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel___getitem____lt_genexpr_gt_),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel___getitem__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_neopixel__lt_module_gt__NeoPixel___getitem__,
    .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel___getitem__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 47,
    .n_obj = 0,
    .n_raw_code = 1,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___getitem__,
        .qstr_source_file = MP_QSTR_neopixel_dot_py,
        .line_info = fun_data_neopixel__lt_module_gt__NeoPixel___getitem__ + 0,
        .opcodes = fun_data_neopixel__lt_module_gt__NeoPixel___getitem__ + 14,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel_fill
STATIC const byte fun_data_neopixel__lt_module_gt__NeoPixel_fill[36] = {
    0x3a, 0x10,
    MP_QSTR_fill & 0xff, MP_QSTR_fill >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x80, 0x1c, 0x2a, 0x00,
    0xb0, 
    0x13, MP_QSTR_n & 0xff, MP_QSTR_n >> 8, 
    0x80, 
    0x42, 0x08, 0x80, 
    0x57, 
    0xc2, 
    0xb1, 
    0xb0, 
    0xb2, 
    0x56, 
    0x81, 
    0xe5, 
    0x58, 
    0x5a, 
    0xd7, 
    0x43, 0xf2, 0x7f, 
    0x59, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel_fill[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_color),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel_fill = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_neopixel__lt_module_gt__NeoPixel_fill,
    .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel_fill,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 36,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_fill,
        .qstr_source_file = MP_QSTR_neopixel_dot_py,
        .line_info = fun_data_neopixel__lt_module_gt__NeoPixel_fill + 0,
        .opcodes = fun_data_neopixel__lt_module_gt__NeoPixel_fill + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel_write
STATIC const byte fun_data_neopixel__lt_module_gt__NeoPixel_write[29] = {
    0x21, 0x0e,
    MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x80, 0x20, 0x00,
    0x12, MP_QSTR_neopixel_write & 0xff, MP_QSTR_neopixel_write >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0xb0, 
    0x13, MP_QSTR_timing & 0xff, MP_QSTR_timing >> 8, 
    0x34, 0x03, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel_write[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel_write = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_neopixel__lt_module_gt__NeoPixel_write,
    .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel_write,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 29,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_write,
        .qstr_source_file = MP_QSTR_neopixel_dot_py,
        .line_info = fun_data_neopixel__lt_module_gt__NeoPixel_write + 0,
        .opcodes = fun_data_neopixel__lt_module_gt__NeoPixel_write + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file neopixel.py, scope neopixel__lt_module_gt__NeoPixel
STATIC const byte fun_data_neopixel__lt_module_gt__NeoPixel[71] = {
    0x18, 0x20,
    MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x8c, 0x07, 0x49, 0x8a, 0x08, 0x65, 0x40, 0x65, 0x40, 0x65, 0x20, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x81, 
    0x80, 
    0x82, 
    0x83, 
    0x2a, 0x04, 
    0x16, MP_QSTR_ORDER & 0xff, MP_QSTR_ORDER >> 8, 
    0x83, 
    0x81, 
    0x2a, 0x02, 
    0x53, 
    0x33, 0x00, 
    0x16, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR___setitem__ & 0xff, MP_QSTR___setitem__ >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR___getitem__ & 0xff, MP_QSTR___getitem__ >> 8, 
    0x32, 0x03, 
    0x16, MP_QSTR_fill & 0xff, MP_QSTR_fill >> 8, 
    0x32, 0x04, 
    0x16, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt__NeoPixel[5] = {
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel___init__),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel___setitem__),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel___getitem__),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel_fill),
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel_write),
};
STATIC const mp_raw_code_t raw_code_neopixel__lt_module_gt__NeoPixel = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_neopixel__lt_module_gt__NeoPixel,
    .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt__NeoPixel,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 71,
    .n_obj = 0,
    .n_raw_code = 5,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_NeoPixel,
        .qstr_source_file = MP_QSTR_neopixel_dot_py,
        .line_info = fun_data_neopixel__lt_module_gt__NeoPixel + 0,
        .opcodes = fun_data_neopixel__lt_module_gt__NeoPixel + 18,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file neopixel.py, scope neopixel_<module>
STATIC const byte fun_data_neopixel__lt_module_gt_[38] = {
    0x10, 0x0e,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_neopixel_dot_py & 0xff, MP_QSTR_neopixel_dot_py >> 8,
    0x60, 0x70, 0x00,
    0x80, 
    0x10, MP_QSTR_neopixel_write & 0xff, MP_QSTR_neopixel_write >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8, 
    0x1c, MP_QSTR_neopixel_write & 0xff, MP_QSTR_neopixel_write >> 8, 
    0x16, MP_QSTR_neopixel_write & 0xff, MP_QSTR_neopixel_write >> 8, 
    0x59, 
    0x54, 
    0x32, 0x00, 
    0x10, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8, 
    0x34, 0x02, 
    0x16, MP_QSTR_NeoPixel & 0xff, MP_QSTR_NeoPixel >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_neopixel__lt_module_gt_[1] = {
    MP_ROM_PTR(&raw_code_neopixel__lt_module_gt__NeoPixel),
};
const mp_raw_code_t raw_code_neopixel__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_neopixel__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_neopixel__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 38,
    .n_obj = 0,
    .n_raw_code = 1,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_neopixel_dot_py,
        .line_info = fun_data_neopixel__lt_module_gt_ + 0,
        .opcodes = fun_data_neopixel__lt_module_gt_ + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__NotFoundError
STATIC const byte fun_data_upip__lt_module_gt__NotFoundError[23] = {
    0x00, 0x0e,
    MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x8c, 0x1a, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__NotFoundError = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip__lt_module_gt__NotFoundError,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_NotFoundError,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__NotFoundError + 0,
        .opcodes = fun_data_upip__lt_module_gt__NotFoundError + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__op_split
STATIC const byte fun_data_upip__lt_module_gt__op_split[82] = {
    0x31, 0x1e,
    MP_QSTR_op_split & 0xff, MP_QSTR_op_split >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x1d, 0x28, 0x29, 0x2b, 0x2b, 0x27, 0x24, 0x24, 0x24, 0x00,
    0xb0, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0xd9, 
    0x44, 0x09, 0x80, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0x2a, 0x02, 
    0x63, 
    0xb0, 
    0x14, MP_QSTR_rsplit & 0xff, MP_QSTR_rsplit >> 8, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0x81, 
    0x36, 0x02, 
    0xc1, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0xb1, 
    0x34, 0x01, 
    0x81, 
    0xd9, 
    0x44, 0x07, 0x80, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0xb0, 
    0x2a, 0x02, 
    0x63, 
    0xb1, 
    0x80, 
    0x55, 
    0xc2, 
    0xb2, 
    0x43, 0x04, 0x80, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0xc2, 
    0xb2, 
    0xb1, 
    0x81, 
    0x55, 
    0x2a, 0x02, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__op_split[1] = {
    MP_ROM_QSTR(MP_QSTR_path),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__op_split = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip__lt_module_gt__op_split,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__op_split,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 82,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_op_split,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__op_split + 0,
        .opcodes = fun_data_upip__lt_module_gt__op_split + 17,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__op_basename
STATIC const byte fun_data_upip__lt_module_gt__op_basename[18] = {
    0x11, 0x0e,
    MP_QSTR_op_basename & 0xff, MP_QSTR_op_basename >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x28, 0x00,
    0x12, MP_QSTR_op_split & 0xff, MP_QSTR_op_split >> 8, 
    0xb0, 
    0x34, 0x01, 
    0x81, 
    0x55, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__op_basename[1] = {
    MP_ROM_QSTR(MP_QSTR_path),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__op_basename = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip__lt_module_gt__op_basename,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__op_basename,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_op_basename,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__op_basename + 0,
        .opcodes = fun_data_upip__lt_module_gt__op_basename + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt___makedirs
STATIC const byte fun_data_upip__lt_module_gt___makedirs[180] = {
    0x82, 0x13, 0x2e,
    MP_QSTR__makedirs & 0xff, MP_QSTR__makedirs >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x2c, 0x22, 0x24, 0x37, 0x2a, 0x24, 0x26, 0x2e, 0x26, 0x24, 0x23, 0x2a, 0x51, 0x1f, 0x21, 0x22, 0x2f, 0x00,
    0x50, 
    0xc2, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0xc3, 
    0xb0, 
    0x14, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0x36, 0x01, 
    0x14, MP_QSTR_split & 0xff, MP_QSTR_split >> 8, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0x36, 0x01, 
    0x51, 
    0x7f, 
    0x2e, 0x02, 
    0x55, 
    0xc4, 
    0xb4, 
    0x80, 
    0x55, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0xd9, 
    0x44, 0x04, 0x80, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0xc3, 
    0xb4, 
    0x5f, 
    0x4b, 0x68, 0x00, 
    0xc5, 
    0xb3, 
    0x44, 0x10, 0x80, 
    0xb3, 
    0x7f, 
    0x55, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0xdc, 
    0x44, 0x06, 0x80, 
    0xb3, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0xe5, 
    0xc3, 
    0xb3, 
    0xb5, 
    0xe5, 
    0xc3, 
    0x48, 0x0f, 0x00, 
    0x12, MP_QSTR_os & 0xff, MP_QSTR_os >> 8, 
    0x14, MP_QSTR_mkdir & 0xff, MP_QSTR_mkdir >> 8, 
    0xb3, 
    0x36, 0x01, 
    0x59, 
    0x52, 
    0xc2, 
    0x4a, 0x3a, 0x00, 
    0x57, 
    0x12, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8, 
    0xdf, 
    0x44, 0x31, 0x80, 
    0xc6, 
    0x49, 0x25, 0x00, 
    0xb6, 
    0x13, MP_QSTR_args & 0xff, MP_QSTR_args >> 8, 
    0x80, 
    0x55, 
    0x12, MP_QSTR_errno & 0xff, MP_QSTR_errno >> 8, 
    0x13, MP_QSTR_EEXIST & 0xff, MP_QSTR_EEXIST >> 8, 
    0xdc, 
    0x44, 0x12, 0x80, 
    0xb6, 
    0x13, MP_QSTR_args & 0xff, MP_QSTR_args >> 8, 
    0x80, 
    0x55, 
    0x12, MP_QSTR_errno & 0xff, MP_QSTR_errno >> 8, 
    0x13, MP_QSTR_EISDIR & 0xff, MP_QSTR_EISDIR >> 8, 
    0xdc, 
    0x44, 0x02, 0x80, 
    0xb6, 
    0x65, 
    0x50, 
    0xc2, 
    0x51, 
    0x51, 
    0xc6, 
    0x28, 0x06, 
    0x5d, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x42, 0x95, 0x7f, 
    0xb2, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt___makedirs[2] = {
    MP_ROM_QSTR(MP_QSTR_name),
    MP_ROM_QSTR(MP_QSTR_mode),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt___makedirs = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip__lt_module_gt___makedirs,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt___makedirs,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 180,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 17,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name = MP_QSTR__makedirs,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt___makedirs + 0,
        .opcodes = fun_data_upip__lt_module_gt___makedirs + 26,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__save_file
STATIC const byte fun_data_upip__lt_module_gt__save_file[64] = {
    0x4e, 0x1a,
    MP_QSTR_save_file & 0xff, MP_QSTR_save_file >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x40, 0x20, 0x2d, 0x20, 0x2a, 0x24, 0x23, 0x00,
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0xb0, 
    0x10, MP_QSTR_wb & 0xff, MP_QSTR_wb >> 8, 
    0x34, 0x02, 
    0x47, 0x21, 0x00, 
    0xc2, 
    0xb1, 
    0x14, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8, 
    0x12, MP_QSTR_file_buf & 0xff, MP_QSTR_file_buf >> 8, 
    0x36, 0x01, 
    0xc3, 
    0xb3, 
    0x43, 0x03, 0x80, 
    0x42, 0x0e, 0x80, 
    0xb2, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0x12, MP_QSTR_file_buf & 0xff, MP_QSTR_file_buf >> 8, 
    0xb3, 
    0x36, 0x02, 
    0x59, 
    0x42, 0xe1, 0x7f, 
    0x51, 
    0x5c, 
    0x5d, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__save_file[2] = {
    MP_ROM_QSTR(MP_QSTR_fname),
    MP_ROM_QSTR(MP_QSTR_subf),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__save_file = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip__lt_module_gt__save_file,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__save_file,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 64,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_save_file,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__save_file + 0,
        .opcodes = fun_data_upip__lt_module_gt__save_file + 15,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__install_tar
STATIC const byte fun_data_upip__lt_module_gt__install_tar[245] = {
    0x9e, 0x10, 0x3c,
    MP_QSTR_install_tar & 0xff, MP_QSTR_install_tar >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x49, 0x23, 0x46, 0x25, 0x23, 0x5d, 0x48, 0x22, 0x50, 0x32, 0x2b, 0x31, 0x22, 0x26, 0x2a, 0x4a, 0x24, 0x24, 0x2e, 0x26, 0x2a, 0x27, 0x28, 0x2b, 0x00,
    0x2c, 0x00, 
    0xc2, 
    0xb0, 
    0x5f, 
    0x4b, 0xca, 0x00, 
    0xc3, 
    0xb3, 
    0x13, MP_QSTR_name & 0xff, MP_QSTR_name >> 8, 
    0xc4, 
    0x48, 0x14, 0x00, 
    0xb4, 
    0xb4, 
    0x14, MP_QSTR_index & 0xff, MP_QSTR_index >> 8, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0x36, 0x01, 
    0x81, 
    0xf2, 
    0x51, 
    0x2e, 0x02, 
    0x55, 
    0xc4, 
    0x4a, 0x11, 0x00, 
    0x57, 
    0x12, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8, 
    0xdf, 
    0x44, 0x08, 0x80, 
    0x59, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0xc4, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x52, 
    0xc5, 
    0x10, MP_QSTR_setup_dot_ & 0xff, MP_QSTR_setup_dot_ >> 8, 
    0x10, MP_QSTR_PKG_hyphen_INFO & 0xff, MP_QSTR_PKG_hyphen_INFO >> 8, 
    0x10, MP_QSTR_README & 0xff, MP_QSTR_README >> 8, 
    0x2a, 0x03, 
    0x5f, 
    0x4b, 0x4b, 0x00, 
    0xc6, 
    0xb4, 
    0x14, MP_QSTR_startswith & 0xff, MP_QSTR_startswith >> 8, 
    0xb6, 
    0x36, 0x01, 
    0x43, 0x08, 0x80, 
    0x10, MP_QSTR__dot_egg_hyphen_info & 0xff, MP_QSTR__dot_egg_hyphen_info >> 8, 
    0xb4, 
    0xdd, 
    0x44, 0x35, 0x80, 
    0xb4, 
    0x14, MP_QSTR_endswith & 0xff, MP_QSTR_endswith >> 8, 
    0x23, 0x02, 
    0x36, 0x01, 
    0x44, 0x11, 0x80, 
    0xb0, 
    0x14, MP_QSTR_extractfile & 0xff, MP_QSTR_extractfile >> 8, 
    0xb3, 
    0x36, 0x01, 
    0x14, MP_QSTR_read & 0xff, MP_QSTR_read >> 8, 
    0x36, 0x00, 
    0xb2, 
    0x10, MP_QSTR_deps & 0xff, MP_QSTR_deps >> 8, 
    0x56, 
    0x50, 
    0xc5, 
    0x12, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x44, 0x0a, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x10, MP_QSTR_Skipping & 0xff, MP_QSTR_Skipping >> 8, 
    0xb4, 
    0x34, 0x02, 
    0x59, 
    0x59, 
    0x59, 
    0x59, 
    0x59, 
    0x42, 0x03, 0x80, 
    0x42, 0xb2, 0x7f, 
    0xb5, 
    0x44, 0x39, 0x80, 
    0xb1, 
    0xb4, 
    0xf2, 
    0xc7, 
    0xb3, 
    0x13, MP_QSTR_type & 0xff, MP_QSTR_type >> 8, 
    0x12, MP_QSTR_tarfile & 0xff, MP_QSTR_tarfile >> 8, 
    0x13, MP_QSTR_DIRTYPE & 0xff, MP_QSTR_DIRTYPE >> 8, 
    0xdc, 
    0x44, 0x27, 0x80, 
    0x12, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x44, 0x0a, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x03, 
    0xb7, 
    0xf2, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR__makedirs & 0xff, MP_QSTR__makedirs >> 8, 
    0xb7, 
    0x34, 0x01, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_extractfile & 0xff, MP_QSTR_extractfile >> 8, 
    0xb3, 
    0x36, 0x01, 
    0xc8, 
    0x12, MP_QSTR_save_file & 0xff, MP_QSTR_save_file >> 8, 
    0xb7, 
    0xb8, 
    0x34, 0x02, 
    0x59, 
    0x42, 0x33, 0x7f, 
    0xb2, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_tar_0 = {{&mp_type_str}, 36962, 13, (const byte*)"\x2f\x72\x65\x71\x75\x69\x72\x65\x73\x2e\x74\x78\x74"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_tar_1 = {{&mp_type_str}, 56712, 11, (const byte*)"\x45\x78\x74\x72\x61\x63\x74\x69\x6e\x67\x20"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__install_tar[4] = {
    MP_ROM_QSTR(MP_QSTR_f),
    MP_ROM_QSTR(MP_QSTR_prefix),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_tar_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_tar_1),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__install_tar = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip__lt_module_gt__install_tar,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__install_tar,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 245,
    .n_obj = 2,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 20,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_install_tar,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__install_tar + 0,
        .opcodes = fun_data_upip__lt_module_gt__install_tar + 33,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__expandhome
STATIC const byte fun_data_upip__lt_module_gt__expandhome[49] = {
    0x31, 0x14,
    MP_QSTR_expandhome & 0xff, MP_QSTR_expandhome >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x68, 0x28, 0x2c, 0x2f, 0x00,
    0x10, MP_QSTR__tilde__slash_ & 0xff, MP_QSTR__tilde__slash_ >> 8, 
    0xb0, 
    0xdd, 
    0x44, 0x1b, 0x80, 
    0x12, MP_QSTR_os & 0xff, MP_QSTR_os >> 8, 
    0x14, MP_QSTR_getenv & 0xff, MP_QSTR_getenv >> 8, 
    0x10, MP_QSTR_HOME & 0xff, MP_QSTR_HOME >> 8, 
    0x36, 0x01, 
    0xc1, 
    0xb0, 
    0x14, MP_QSTR_replace & 0xff, MP_QSTR_replace >> 8, 
    0x10, MP_QSTR__tilde__slash_ & 0xff, MP_QSTR__tilde__slash_ >> 8, 
    0xb1, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0xf2, 
    0x36, 0x02, 
    0xc0, 
    0xb0, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__expandhome[1] = {
    MP_ROM_QSTR(MP_QSTR_s),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__expandhome = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip__lt_module_gt__expandhome,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__expandhome,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 49,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_expandhome,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__expandhome + 0,
        .opcodes = fun_data_upip__lt_module_gt__expandhome + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__url_open
STATIC const byte fun_data_upip__lt_module_gt__url_open[346] = {
    0x89, 0x12, 0x4e,
    MP_QSTR_url_open & 0xff, MP_QSTR_url_open >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x71, 0x40, 0x26, 0x47, 0x30, 0x23, 0x1f, 0x44, 0x55, 0x44, 0x32, 0x43, 0x4a, 0x28, 0x2f, 0x26, 0x2a, 0x64, 0x2e, 0x27, 0x2d, 0x27, 0x2e, 0x28, 0x27, 0x20, 0x27, 0x24, 0x28, 0x27, 0x55, 0x27, 0x4c, 0x00,
    0x12, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x44, 0x07, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0xb0, 
    0x34, 0x01, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_split & 0xff, MP_QSTR_split >> 8, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0x83, 
    0x36, 0x02, 
    0x30, 0x04, 
    0xc1, 
    0xc2, 
    0xc3, 
    0xc4, 
    0x48, 0x17, 0x00, 
    0x12, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8, 
    0x14, MP_QSTR_getaddrinfo & 0xff, MP_QSTR_getaddrinfo >> 8, 
    0xb3, 
    0x22, 0x83, 0x3b, 
    0x80, 
    0x12, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8, 
    0x13, MP_QSTR_SOCK_STREAM & 0xff, MP_QSTR_SOCK_STREAM >> 8, 
    0x36, 0x04, 
    0xc5, 
    0x4a, 0x21, 0x00, 
    0x57, 
    0x12, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8, 
    0xdf, 
    0x44, 0x18, 0x80, 
    0xc6, 
    0x49, 0x0c, 0x00, 
    0x12, MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8, 
    0x23, 0x01, 
    0xb3, 
    0xf8, 
    0xb6, 
    0x34, 0x02, 
    0x59, 
    0x51, 
    0x51, 
    0xc6, 
    0x28, 0x06, 
    0x5d, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0xb5, 
    0x80, 
    0x55, 
    0xc5, 
    0x12, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8, 
    0x14, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0xb5, 
    0x80, 
    0x55, 
    0xb5, 
    0x81, 
    0x55, 
    0xb5, 
    0x82, 
    0x55, 
    0x36, 0x03, 
    0xc7, 
    0x48, 0x9e, 0x00, 
    0xb7, 
    0x14, MP_QSTR_connect & 0xff, MP_QSTR_connect >> 8, 
    0xb5, 
    0x7f, 
    0x55, 
    0x36, 0x01, 
    0x59, 
    0xb1, 
    0x10, MP_QSTR_https_colon_ & 0xff, MP_QSTR_https_colon_ >> 8, 
    0xd9, 
    0x44, 0x23, 0x80, 
    0x12, MP_QSTR_ussl & 0xff, MP_QSTR_ussl >> 8, 
    0x14, MP_QSTR_wrap_socket & 0xff, MP_QSTR_wrap_socket >> 8, 
    0xb7, 
    0x10, MP_QSTR_server_hostname & 0xff, MP_QSTR_server_hostname >> 8, 
    0xb3, 
    0x36, 0x82, 0x01, 
    0xc7, 
    0x12, MP_QSTR_warn_ussl & 0xff, MP_QSTR_warn_ussl >> 8, 
    0x44, 0x0e, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x02, 
    0xb3, 
    0xf8, 
    0x34, 0x01, 
    0x59, 
    0x50, 
    0x17, MP_QSTR_warn_ussl & 0xff, MP_QSTR_warn_ussl >> 8, 
    0xb7, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0x23, 0x03, 
    0xb4, 
    0xb3, 
    0x2a, 0x02, 
    0xf8, 
    0x36, 0x01, 
    0x59, 
    0xb7, 
    0x14, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8, 
    0x36, 0x00, 
    0xc8, 
    0xb8, 
    0x14, MP_QSTR_split & 0xff, MP_QSTR_split >> 8, 
    0x51, 
    0x82, 
    0x36, 0x02, 
    0x30, 0x03, 
    0xc9, 
    0xca, 
    0xcb, 
    0xba, 
    0x23, 0x04, 
    0xdc, 
    0x44, 0x1d, 0x80, 
    0xba, 
    0x23, 0x05, 
    0xd9, 
    0x43, 0x07, 0x80, 
    0xba, 
    0x23, 0x06, 
    0xd9, 
    0x44, 0x08, 0x80, 
    0x12, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8, 
    0x23, 0x07, 
    0x34, 0x01, 
    0x65, 
    0x12, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8, 
    0xba, 
    0x34, 0x01, 
    0x65, 
    0xb7, 
    0x14, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8, 
    0x36, 0x00, 
    0xc8, 
    0xb8, 
    0x43, 0x08, 0x80, 
    0x12, MP_QSTR_ValueError & 0xff, MP_QSTR_ValueError >> 8, 
    0x23, 0x08, 
    0x34, 0x01, 
    0x65, 
    0xb8, 
    0x23, 0x09, 
    0xd9, 
    0x44, 0x03, 0x80, 
    0x42, 0x03, 0x80, 
    0x42, 0xe0, 0x7f, 
    0x4a, 0x1f, 0x00, 
    0x57, 
    0x12, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8, 
    0xdf, 
    0x44, 0x16, 0x80, 
    0xc6, 
    0x49, 0x0a, 0x00, 
    0xb7, 
    0x14, MP_QSTR_close & 0xff, MP_QSTR_close >> 8, 
    0x36, 0x00, 
    0x59, 
    0xb6, 
    0x65, 
    0x51, 
    0x51, 
    0xc6, 
    0x28, 0x06, 
    0x5d, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0xb7, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_0 = {{&mp_type_str}, 10889, 35, (const byte*)"\x55\x6e\x61\x62\x6c\x65\x20\x74\x6f\x20\x72\x65\x73\x6f\x6c\x76\x65\x20\x25\x73\x20\x28\x6e\x6f\x20\x49\x6e\x74\x65\x72\x6e\x65\x74\x3f\x29"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_1 = {{&mp_type_str}, 51159, 44, (const byte*)"\x57\x61\x72\x6e\x69\x6e\x67\x3a\x20\x25\x73\x20\x53\x53\x4c\x20\x63\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x20\x69\x73\x20\x6e\x6f\x74\x20\x76\x61\x6c\x69\x64\x61\x74\x65\x64"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_2 = {{&mp_type_str}, 26169, 30, (const byte*)"\x47\x45\x54\x20\x2f\x25\x73\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\x0d\x0a\x48\x6f\x73\x74\x3a\x20\x25\x73\x0d\x0a\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_3 = {{&mp_type_bytes}, 28951, 3, (const byte*)"\x32\x30\x30"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_4 = {{&mp_type_bytes}, 22421, 3, (const byte*)"\x34\x30\x34"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_5 = {{&mp_type_bytes}, 29975, 3, (const byte*)"\x33\x30\x31"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_6 = {{&mp_type_str}, 48284, 17, (const byte*)"\x50\x61\x63\x6b\x61\x67\x65\x20\x6e\x6f\x74\x20\x66\x6f\x75\x6e\x64"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_7 = {{&mp_type_str}, 39199, 30, (const byte*)"\x55\x6e\x65\x78\x70\x65\x63\x74\x65\x64\x20\x45\x4f\x46\x20\x69\x6e\x20\x48\x54\x54\x50\x20\x68\x65\x61\x64\x65\x72\x73"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__url_open_8 = {{&mp_type_bytes}, 27298, 2, (const byte*)"\x0d\x0a"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__url_open[10] = {
    MP_ROM_QSTR(MP_QSTR_url),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_1),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_2),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_3),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_4),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_5),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_6),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_7),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__url_open_8),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__url_open = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip__lt_module_gt__url_open,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__url_open,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 346,
    .n_obj = 9,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 18,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_url_open,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__url_open + 0,
        .opcodes = fun_data_upip__lt_module_gt__url_open + 42,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__get_pkg_metadata
STATIC const byte fun_data_upip__lt_module_gt__get_pkg_metadata[96] = {
    0x65, 0x1c,
    MP_QSTR_get_pkg_metadata & 0xff, MP_QSTR_get_pkg_metadata >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x9f, 0x28, 0x23, 0x5a, 0x28, 0x23, 0x4b, 0x2b, 0x00,
    0x12, MP_QSTR_index_urls & 0xff, MP_QSTR_index_urls >> 8, 
    0x5f, 
    0x4b, 0x3f, 0x00, 
    0xc1, 
    0x48, 0x11, 0x00, 
    0x12, MP_QSTR_url_open & 0xff, MP_QSTR_url_open >> 8, 
    0x10, MP_QSTR__percent_s_slash__percent_s_slash_json & 0xff, MP_QSTR__percent_s_slash__percent_s_slash_json >> 8, 
    0xb1, 
    0xb0, 
    0x2a, 0x02, 
    0xf8, 
    0x34, 0x01, 
    0xc2, 
    0x4a, 0x11, 0x00, 
    0x57, 
    0x12, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8, 
    0xdf, 
    0x44, 0x08, 0x80, 
    0x59, 
    0x40, 0xdc, 0x7f, 0x01, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x49, 0x0b, 0x00, 
    0x12, MP_QSTR_json & 0xff, MP_QSTR_json >> 8, 
    0x14, MP_QSTR_load & 0xff, MP_QSTR_load >> 8, 
    0xb2, 
    0x36, 0x01, 
    0x63, 
    0x51, 
    0xb2, 
    0x14, MP_QSTR_close & 0xff, MP_QSTR_close >> 8, 
    0x36, 0x00, 
    0x59, 
    0x5d, 
    0x42, 0xbe, 0x7f, 
    0x12, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8, 
    0x23, 0x01, 
    0x34, 0x01, 
    0x65, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__get_pkg_metadata_0 = {{&mp_type_str}, 48284, 17, (const byte*)"\x50\x61\x63\x6b\x61\x67\x65\x20\x6e\x6f\x74\x20\x66\x6f\x75\x6e\x64"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__get_pkg_metadata[2] = {
    MP_ROM_QSTR(MP_QSTR_name),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__get_pkg_metadata_0),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__get_pkg_metadata = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip__lt_module_gt__get_pkg_metadata,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__get_pkg_metadata,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 96,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_get_pkg_metadata,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__get_pkg_metadata + 0,
        .opcodes = fun_data_upip__lt_module_gt__get_pkg_metadata + 16,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__fatal
STATIC const byte fun_data_upip__lt_module_gt__fatal[47] = {
    0xa2, 0x01, 0x14,
    MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0xac, 0x2a, 0x2a, 0x22, 0x00,
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x10, MP_QSTR_Error_colon_ & 0xff, MP_QSTR_Error_colon_ >> 8, 
    0xb0, 
    0x34, 0x02, 
    0x59, 
    0xb1, 
    0x44, 0x08, 0x80, 
    0x12, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x44, 0x02, 0x80, 
    0xb1, 
    0x65, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x14, MP_QSTR_exit & 0xff, MP_QSTR_exit >> 8, 
    0x81, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__fatal[2] = {
    MP_ROM_QSTR(MP_QSTR_msg),
    MP_ROM_QSTR(MP_QSTR_exc),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__fatal = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip__lt_module_gt__fatal,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__fatal,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 47,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name = MP_QSTR_fatal,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__fatal + 0,
        .opcodes = fun_data_upip__lt_module_gt__fatal + 13,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__install_pkg
STATIC const byte fun_data_upip__lt_module_gt__install_pkg[177] = {
    0x8e, 0x10, 0x32,
    MP_QSTR_install_pkg & 0xff, MP_QSTR_install_pkg >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0xb2, 0x47, 0x2a, 0x28, 0x22, 0x29, 0x2f, 0x28, 0x2e, 0x27, 0x27, 0x23, 0x2d, 0x2e, 0x49, 0x28, 0x22, 0x22, 0x29, 0x00,
    0x12, MP_QSTR_get_pkg_metadata & 0xff, MP_QSTR_get_pkg_metadata >> 8, 
    0xb0, 
    0x34, 0x01, 
    0xc2, 
    0xb2, 
    0x10, MP_QSTR_info & 0xff, MP_QSTR_info >> 8, 
    0x55, 
    0x10, MP_QSTR_version & 0xff, MP_QSTR_version >> 8, 
    0x55, 
    0xc3, 
    0xb2, 
    0x10, MP_QSTR_releases & 0xff, MP_QSTR_releases >> 8, 
    0x55, 
    0xb3, 
    0x55, 
    0xc4, 
    0x28, 0x02, 
    0x12, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x14, MP_QSTR_collect & 0xff, MP_QSTR_collect >> 8, 
    0x36, 0x00, 
    0x59, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0xb4, 
    0x34, 0x01, 
    0x81, 
    0xd9, 
    0x43, 0x04, 0x80, 
    0x12, MP_QSTR_AssertionError & 0xff, MP_QSTR_AssertionError >> 8, 
    0x65, 
    0xb4, 
    0x80, 
    0x55, 
    0x10, MP_QSTR_url & 0xff, MP_QSTR_url >> 8, 
    0x55, 
    0xc5, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x02, 
    0xb0, 
    0xb3, 
    0xb5, 
    0x2a, 0x03, 
    0xf8, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_op_basename & 0xff, MP_QSTR_op_basename >> 8, 
    0xb5, 
    0x34, 0x01, 
    0xc6, 
    0x12, MP_QSTR_url_open & 0xff, MP_QSTR_url_open >> 8, 
    0xb5, 
    0x34, 0x01, 
    0xc7, 
    0x49, 0x24, 0x00, 
    0x12, MP_QSTR_uzlib & 0xff, MP_QSTR_uzlib >> 8, 
    0x14, MP_QSTR_DecompIO & 0xff, MP_QSTR_DecompIO >> 8, 
    0xb7, 
    0x12, MP_QSTR_gzdict_sz & 0xff, MP_QSTR_gzdict_sz >> 8, 
    0x36, 0x02, 
    0xc8, 
    0x12, MP_QSTR_tarfile & 0xff, MP_QSTR_tarfile >> 8, 
    0x14, MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8, 
    0x10, MP_QSTR_fileobj & 0xff, MP_QSTR_fileobj >> 8, 
    0xb8, 
    0x36, 0x82, 0x00, 
    0xc9, 
    0x12, MP_QSTR_install_tar & 0xff, MP_QSTR_install_tar >> 8, 
    0xb9, 
    0xb1, 
    0x34, 0x02, 
    0xca, 
    0x51, 
    0xb7, 
    0x14, MP_QSTR_close & 0xff, MP_QSTR_close >> 8, 
    0x36, 0x00, 
    0x59, 
    0x5d, 
    0x28, 0x09, 
    0x28, 0x08, 
    0x12, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x14, MP_QSTR_collect & 0xff, MP_QSTR_collect >> 8, 
    0x36, 0x00, 
    0x59, 
    0xba, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_pkg_0 = {{&mp_type_str}, 7236, 24, (const byte*)"\x49\x6e\x73\x74\x61\x6c\x6c\x69\x6e\x67\x20\x25\x73\x20\x25\x73\x20\x66\x72\x6f\x6d\x20\x25\x73"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__install_pkg[3] = {
    MP_ROM_QSTR(MP_QSTR_pkg_spec),
    MP_ROM_QSTR(MP_QSTR_install_path),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_pkg_0),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__install_pkg = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip__lt_module_gt__install_pkg,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__install_pkg,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 177,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 18,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_install_pkg,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__install_pkg + 0,
        .opcodes = fun_data_upip__lt_module_gt__install_pkg + 28,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__install
STATIC const byte fun_data_upip__lt_module_gt__install[298] = {
    0xfa, 0x03, 0x46,
    MP_QSTR_install & 0xff, MP_QSTR_install >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0xca, 0x20, 0x32, 0x29, 0x44, 0x26, 0x26, 0x2a, 0x26, 0x2c, 0x24, 0x4a, 0x23, 0x23, 0x23, 0x26, 0x2a, 0x28, 0x26, 0x23, 0x28, 0x28, 0x26, 0x27, 0x32, 0x24, 0x32, 0x5b, 0x4f, 0x00,
    0x12, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x14, MP_QSTR_mem_free & 0xff, MP_QSTR_mem_free >> 8, 
    0x36, 0x00, 
    0x12, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x14, MP_QSTR_mem_alloc & 0xff, MP_QSTR_mem_alloc >> 8, 
    0x36, 0x00, 
    0xf2, 
    0xc2, 
    0xb2, 
    0x22, 0x84, 0x80, 0x00, 
    0xda, 
    0x44, 0x04, 0x80, 
    0x9c, 
    0x17, MP_QSTR_gzdict_sz & 0xff, MP_QSTR_gzdict_sz >> 8, 
    0xb1, 
    0x51, 
    0xde, 
    0x44, 0x06, 0x80, 
    0x12, MP_QSTR_get_install_path & 0xff, MP_QSTR_get_install_path >> 8, 
    0x34, 0x00, 
    0xc1, 
    0xb1, 
    0x7f, 
    0x55, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0xdc, 
    0x44, 0x06, 0x80, 
    0xb1, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0xe5, 
    0xc1, 
    0x12, MP_QSTR_isinstance & 0xff, MP_QSTR_isinstance >> 8, 
    0xb0, 
    0x12, MP_QSTR_list & 0xff, MP_QSTR_list >> 8, 
    0x34, 0x02, 
    0x43, 0x04, 0x80, 
    0xb0, 
    0x2b, 0x01, 
    0xc0, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x02, 
    0xb1, 
    0xf2, 
    0x34, 0x01, 
    0x59, 
    0x2b, 0x00, 
    0xc3, 
    0x48, 0x78, 0x00, 
    0x42, 0x6e, 0x80, 
    0x12, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x44, 0x0a, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x10, MP_QSTR_Queue_colon_ & 0xff, MP_QSTR_Queue_colon_ >> 8, 
    0xb0, 
    0x34, 0x02, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_pop & 0xff, MP_QSTR_pop >> 8, 
    0x80, 
    0x36, 0x01, 
    0xc4, 
    0xb4, 
    0xb3, 
    0xdd, 
    0x44, 0x03, 0x80, 
    0x42, 0x4d, 0x80, 
    0x12, MP_QSTR_install_pkg & 0xff, MP_QSTR_install_pkg >> 8, 
    0xb4, 
    0xb1, 
    0x34, 0x02, 
    0xc5, 
    0xb3, 
    0x14, MP_QSTR_append & 0xff, MP_QSTR_append >> 8, 
    0xb4, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x44, 0x07, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0xb5, 
    0x34, 0x01, 
    0x59, 
    0xb5, 
    0x14, MP_QSTR_get & 0xff, MP_QSTR_get >> 8, 
    0x10, MP_QSTR_deps & 0xff, MP_QSTR_deps >> 8, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0x36, 0x02, 
    0x14, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8, 
    0x36, 0x00, 
    0xc6, 
    0xb6, 
    0x44, 0x1a, 0x80, 
    0xb6, 
    0x14, MP_QSTR_decode & 0xff, MP_QSTR_decode >> 8, 
    0x10, MP_QSTR_utf_hyphen_8 & 0xff, MP_QSTR_utf_hyphen_8 >> 8, 
    0x36, 0x01, 
    0x14, MP_QSTR_split & 0xff, MP_QSTR_split >> 8, 
    0x10, MP_QSTR__0x0a_ & 0xff, MP_QSTR__0x0a_ >> 8, 
    0x36, 0x01, 
    0xc6, 
    0xb0, 
    0x14, MP_QSTR_extend & 0xff, MP_QSTR_extend >> 8, 
    0xb6, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x43, 0x8e, 0x7f, 
    0x4a, 0x2f, 0x00, 
    0x57, 
    0x12, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8, 
    0xdf, 
    0x44, 0x26, 0x80, 
    0xc7, 
    0x49, 0x1a, 0x00, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x03, 
    0x14, MP_QSTR_format & 0xff, MP_QSTR_format >> 8, 
    0xb4, 
    0xb7, 
    0x36, 0x02, 
    0x10, MP_QSTR_file & 0xff, MP_QSTR_file >> 8, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_stderr & 0xff, MP_QSTR_stderr >> 8, 
    0x34, 0x82, 0x01, 
    0x59, 
    0x51, 
    0x51, 
    0xc7, 
    0x28, 0x07, 
    0x5d, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_0 = {{&mp_type_str}, 1253, 15, (const byte*)"\x49\x6e\x73\x74\x61\x6c\x6c\x69\x6e\x67\x20\x74\x6f\x3a\x20"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__install_1 = {{&mp_type_str}, 31671, 62, (const byte*)"\x45\x72\x72\x6f\x72\x20\x69\x6e\x73\x74\x61\x6c\x6c\x69\x6e\x67\x20\x27\x7b\x7d\x27\x3a\x20\x7b\x7d\x2c\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x6d\x61\x79\x20\x62\x65\x20\x70\x61\x72\x74\x69\x61\x6c\x6c\x79\x20\x69\x6e\x73\x74\x61\x6c\x6c\x65\x64"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__install[4] = {
    MP_ROM_QSTR(MP_QSTR_to_install),
    MP_ROM_QSTR(MP_QSTR_install_path),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__install_1),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__install = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip__lt_module_gt__install,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__install,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 298,
    .n_obj = 2,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 16,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name = MP_QSTR_install,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__install + 0,
        .opcodes = fun_data_upip__lt_module_gt__install + 38,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__get_install_path
STATIC const byte fun_data_upip__lt_module_gt__get_install_path[47] = {
    0x08, 0x16,
    MP_QSTR_get_install_path & 0xff, MP_QSTR_get_install_path >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0xed, 0x20, 0x48, 0x2b, 0x2b, 0x00,
    0x12, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8, 
    0x51, 
    0xde, 
    0x44, 0x0b, 0x80, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_path & 0xff, MP_QSTR_path >> 8, 
    0x81, 
    0x55, 
    0x17, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8, 
    0x12, MP_QSTR_expandhome & 0xff, MP_QSTR_expandhome >> 8, 
    0x12, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8, 
    0x34, 0x01, 
    0x17, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8, 
    0x12, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__get_install_path = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip__lt_module_gt__get_install_path,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 47,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_get_install_path,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__get_install_path + 0,
        .opcodes = fun_data_upip__lt_module_gt__get_install_path + 13,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__cleanup
STATIC const byte fun_data_upip__lt_module_gt__cleanup[64] = {
    0x54, 0x14,
    MP_QSTR_cleanup & 0xff, MP_QSTR_cleanup >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0xf5, 0x28, 0x23, 0x56, 0x00,
    0x12, MP_QSTR_cleanup_files & 0xff, MP_QSTR_cleanup_files >> 8, 
    0x5f, 
    0x4b, 0x2b, 0x00, 
    0xc0, 
    0x48, 0x0d, 0x00, 
    0x12, MP_QSTR_os & 0xff, MP_QSTR_os >> 8, 
    0x14, MP_QSTR_unlink & 0xff, MP_QSTR_unlink >> 8, 
    0xb0, 
    0x36, 0x01, 
    0x59, 
    0x4a, 0x17, 0x00, 
    0x57, 
    0x12, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8, 
    0xdf, 
    0x44, 0x0e, 0x80, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x00, 
    0xb0, 
    0xf2, 
    0x34, 0x01, 
    0x59, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x42, 0xd2, 0x7f, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__cleanup_0 = {{&mp_type_str}, 17877, 23, (const byte*)"\x57\x61\x72\x6e\x69\x6e\x67\x3a\x20\x43\x61\x6e\x6e\x6f\x74\x20\x64\x65\x6c\x65\x74\x65\x20"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__cleanup[1] = {
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__cleanup_0),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__cleanup = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip__lt_module_gt__cleanup,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__cleanup,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 64,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_cleanup,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__cleanup + 0,
        .opcodes = fun_data_upip__lt_module_gt__cleanup + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__help
STATIC const byte fun_data_upip__lt_module_gt__help[46] = {
    0x18, 0x14,
    MP_QSTR_help & 0xff, MP_QSTR_help >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0xfc, 0x88, 0x08, 0x30, 0x00,
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x00, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x01, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_path & 0xff, MP_QSTR_path >> 8, 
    0x81, 
    0x55, 
    0x34, 0x02, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x02, 
    0x34, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__help_0 = {{&mp_type_str}, 14525, 341, (const byte*)"\x75\x70\x69\x70\x20\x2d\x20\x53\x69\x6d\x70\x6c\x65\x20\x50\x79\x50\x49\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x6d\x61\x6e\x61\x67\x65\x72\x20\x66\x6f\x72\x20\x4d\x69\x63\x72\x6f\x50\x79\x74\x68\x6f\x6e\x0a\x55\x73\x61\x67\x65\x3a\x20\x6d\x69\x63\x72\x6f\x70\x79\x74\x68\x6f\x6e\x20\x2d\x6d\x20\x75\x70\x69\x70\x20\x69\x6e\x73\x74\x61\x6c\x6c\x20\x5b\x2d\x70\x20\x3c\x70\x61\x74\x68\x3e\x5d\x20\x3c\x70\x61\x63\x6b\x61\x67\x65\x3e\x2e\x2e\x2e\x20\x7c\x20\x2d\x72\x20\x3c\x72\x65\x71\x75\x69\x72\x65\x6d\x65\x6e\x74\x73\x2e\x74\x78\x74\x3e\x0a\x69\x6d\x70\x6f\x72\x74\x20\x75\x70\x69\x70\x3b\x20\x75\x70\x69\x70\x2e\x69\x6e\x73\x74\x61\x6c\x6c\x28\x70\x61\x63\x6b\x61\x67\x65\x5f\x6f\x72\x5f\x6c\x69\x73\x74\x2c\x20\x5b\x3c\x70\x61\x74\x68\x3e\x5d\x29\x0a\x0a\x49\x66\x20\x3c\x70\x61\x74\x68\x3e\x20\x69\x73\x20\x6e\x6f\x74\x20\x67\x69\x76\x65\x6e\x2c\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x69\x6e\x73\x74\x61\x6c\x6c\x65\x64\x20\x69\x6e\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x5b\x31\x5d\x0a\x28\x63\x61\x6e\x20\x62\x65\x20\x73\x65\x74\x20\x66\x72\x6f\x6d\x20\x4d\x49\x43\x52\x4f\x50\x59\x50\x41\x54\x48\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x2c\x20\x69\x66\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x73\x79\x73\x74\x65\x6d\x0a\x73\x75\x70\x70\x6f\x72\x74\x73\x20\x74\x68\x61\x74\x29\x2e"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__help_1 = {{&mp_type_str}, 17177, 29, (const byte*)"\x43\x75\x72\x72\x65\x6e\x74\x20\x76\x61\x6c\x75\x65\x20\x6f\x66\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x5b\x31\x5d\x3a"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__help_2 = {{&mp_type_str}, 34882, 146, (const byte*)"\x0a\x4e\x6f\x74\x65\x3a\x20\x6f\x6e\x6c\x79\x20\x4d\x69\x63\x72\x6f\x50\x79\x74\x68\x6f\x6e\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x28\x75\x73\x75\x61\x6c\x6c\x79\x2c\x20\x6e\x61\x6d\x65\x64\x20\x6d\x69\x63\x72\x6f\x70\x79\x74\x68\x6f\x6e\x2d\x2a\x29\x20\x61\x72\x65\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x0a\x66\x6f\x72\x20\x69\x6e\x73\x74\x61\x6c\x6c\x61\x74\x69\x6f\x6e\x2c\x20\x75\x70\x69\x70\x20\x64\x6f\x65\x73\x20\x6e\x6f\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x20\x61\x72\x62\x69\x74\x72\x61\x72\x79\x20\x63\x6f\x64\x65\x20\x69\x6e\x20\x73\x65\x74\x75\x70\x2e\x70\x79\x2e\x0a"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__help[3] = {
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__help_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__help_1),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__help_2),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__help = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip__lt_module_gt__help,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__help,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 46,
    .n_obj = 3,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_help,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__help + 0,
        .opcodes = fun_data_upip__lt_module_gt__help + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip__lt_module_gt__main
STATIC const byte fun_data_upip__lt_module_gt__main[423] = {
    0x5c, 0x68,
    MP_QSTR_main & 0xff, MP_QSTR_main >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x90, 0x0c, 0x20, 0x20, 0x20, 0x44, 0x1f, 0x2f, 0x26, 0x42, 0x2f, 0x48, 0x43, 0x22, 0x23, 0x29, 0x24, 0x30, 0x26, 0x22, 0x28, 0x2b, 0x27, 0x28, 0x29, 0x24, 0x2a, 0x20, 0x27, 0x24, 0x23, 0x2a, 0x23, 0x36, 0x28, 0x2d, 0x27, 0x28, 0x47, 0x1f, 0x4c, 0x32, 0x24, 0x26, 0x42, 0x47, 0x26, 0x00,
    0x51, 
    0x17, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0x34, 0x01, 
    0x82, 
    0xd7, 
    0x43, 0x1e, 0x80, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0x81, 
    0x55, 
    0x10, MP_QSTR__hyphen_h & 0xff, MP_QSTR__hyphen_h >> 8, 
    0xd9, 
    0x43, 0x0f, 0x80, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0x81, 
    0x55, 
    0x10, MP_QSTR__hyphen__hyphen_help & 0xff, MP_QSTR__hyphen__hyphen_help >> 8, 
    0xd9, 
    0x44, 0x08, 0x80, 
    0x12, MP_QSTR_help & 0xff, MP_QSTR_help >> 8, 
    0x34, 0x00, 
    0x59, 
    0x51, 
    0x63, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0x81, 
    0x55, 
    0x10, MP_QSTR_install & 0xff, MP_QSTR_install >> 8, 
    0xdc, 
    0x44, 0x08, 0x80, 
    0x12, MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8, 
    0x23, 0x00, 
    0x34, 0x01, 
    0x59, 
    0x2b, 0x00, 
    0xc0, 
    0x82, 
    0xc1, 
    0x42, 0xc4, 0x80, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0xb1, 
    0x55, 
    0xc2, 
    0xb1, 
    0x81, 
    0xe5, 
    0xc1, 
    0xb2, 
    0x10, MP_QSTR__hyphen_h & 0xff, MP_QSTR__hyphen_h >> 8, 
    0xd9, 
    0x43, 0x08, 0x80, 
    0xb2, 
    0x10, MP_QSTR__hyphen__hyphen_help & 0xff, MP_QSTR__hyphen__hyphen_help >> 8, 
    0xd9, 
    0x44, 0x08, 0x80, 
    0x12, MP_QSTR_help & 0xff, MP_QSTR_help >> 8, 
    0x34, 0x00, 
    0x59, 
    0x51, 
    0x63, 
    0xb2, 
    0x10, MP_QSTR__hyphen_p & 0xff, MP_QSTR__hyphen_p >> 8, 
    0xd9, 
    0x44, 0x12, 0x80, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0xb1, 
    0x55, 
    0x17, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8, 
    0xb1, 
    0x81, 
    0xe5, 
    0xc1, 
    0x42, 0x85, 0x80, 
    0xb2, 
    0x10, MP_QSTR__hyphen_r & 0xff, MP_QSTR__hyphen_r >> 8, 
    0xd9, 
    0x44, 0x48, 0x80, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0xb1, 
    0x55, 
    0xc3, 
    0xb1, 
    0x81, 
    0xe5, 
    0xc1, 
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0xb3, 
    0x34, 0x01, 
    0x47, 0x2d, 0x00, 
    0xc4, 
    0xb4, 
    0x14, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8, 
    0x36, 0x00, 
    0xc5, 
    0xb5, 
    0x43, 0x03, 0x80, 
    0x42, 0x1d, 0x80, 
    0xb5, 
    0x80, 
    0x55, 
    0x10, MP_QSTR__hash_ & 0xff, MP_QSTR__hash_ >> 8, 
    0xd9, 
    0x44, 0x03, 0x80, 
    0x42, 0x0d, 0x80, 
    0xb0, 
    0x14, MP_QSTR_append & 0xff, MP_QSTR_append >> 8, 
    0xb5, 
    0x14, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8, 
    0x36, 0x00, 
    0x36, 0x01, 
    0x59, 
    0x42, 0xd5, 0x7f, 
    0x51, 
    0x5c, 
    0x5d, 
    0x42, 0x35, 0x80, 
    0xb2, 
    0x10, MP_QSTR__hyphen_i & 0xff, MP_QSTR__hyphen_i >> 8, 
    0xd9, 
    0x44, 0x14, 0x80, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0xb1, 
    0x55, 
    0x2b, 0x01, 
    0x17, MP_QSTR_index_urls & 0xff, MP_QSTR_index_urls >> 8, 
    0xb1, 
    0x81, 
    0xe5, 
    0xc1, 
    0x42, 0x19, 0x80, 
    0xb2, 
    0x10, MP_QSTR__hyphen__hyphen_debug & 0xff, MP_QSTR__hyphen__hyphen_debug >> 8, 
    0xd9, 
    0x44, 0x07, 0x80, 
    0x52, 
    0x17, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x42, 0x0a, 0x80, 
    0x12, MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8, 
    0x23, 0x01, 
    0xb2, 
    0xf2, 
    0x34, 0x01, 
    0x59, 
    0xb1, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0x34, 0x01, 
    0xd7, 
    0x44, 0x11, 0x80, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0xb1, 
    0x55, 
    0x80, 
    0x55, 
    0x10, MP_QSTR__hyphen_ & 0xff, MP_QSTR__hyphen_ >> 8, 
    0xd9, 
    0x43, 0x1b, 0x7f, 
    0xb0, 
    0x14, MP_QSTR_extend & 0xff, MP_QSTR_extend >> 8, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x13, MP_QSTR_argv & 0xff, MP_QSTR_argv >> 8, 
    0xb1, 
    0x51, 
    0x2e, 0x02, 
    0x55, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x43, 0x08, 0x80, 
    0x12, MP_QSTR_help & 0xff, MP_QSTR_help >> 8, 
    0x34, 0x00, 
    0x59, 
    0x51, 
    0x63, 
    0x12, MP_QSTR_install & 0xff, MP_QSTR_install >> 8, 
    0xb0, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x43, 0x06, 0x80, 
    0x12, MP_QSTR_cleanup & 0xff, MP_QSTR_cleanup >> 8, 
    0x34, 0x00, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__main_0 = {{&mp_type_str}, 50937, 32, (const byte*)"\x4f\x6e\x6c\x79\x20\x27\x69\x6e\x73\x74\x61\x6c\x6c\x27\x20\x63\x6f\x6d\x6d\x61\x6e\x64\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__main_1 = {{&mp_type_str}, 40302, 28, (const byte*)"\x55\x6e\x6b\x6e\x6f\x77\x6e\x2f\x75\x6e\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x6f\x70\x74\x69\x6f\x6e\x3a\x20"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt__main[2] = {
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__main_0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__main_1),
};
STATIC const mp_raw_code_t raw_code_upip__lt_module_gt__main = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip__lt_module_gt__main,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt__main,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 423,
    .n_obj = 2,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_main,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt__main + 0,
        .opcodes = fun_data_upip__lt_module_gt__main + 54,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip.py, scope upip_<module>
STATIC const byte fun_data_upip__lt_module_gt_[301] = {
    0x18, 0x70,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_upip_dot_py & 0xff, MP_QSTR_upip_dot_py >> 8,
    0x80, 0x07, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x69, 0x24, 0x29, 0x24, 0x25, 0x44, 0x4b, 0x6e, 0x85, 0x0b, 0x65, 0x20, 0x8b, 0x14, 0x85, 0x09, 0x85, 0x1f, 0x65, 0x60, 0x28, 0x28, 0x24, 0x85, 0x2e, 0x85, 0x0d, 0x69, 0x60, 0x85, 0x17, 0x89, 0x24, 0x85, 0x08, 0x85, 0x07, 0x85, 0x10, 0x85, 0x37, 0x2a, 0x00,
    0x80, 
    0x51, 
    0x1b, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x16, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x16, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x16, MP_QSTR_os & 0xff, MP_QSTR_os >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uerrno & 0xff, MP_QSTR_uerrno >> 8, 
    0x16, MP_QSTR_errno & 0xff, MP_QSTR_errno >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_ujson & 0xff, MP_QSTR_ujson >> 8, 
    0x16, MP_QSTR_json & 0xff, MP_QSTR_json >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uzlib & 0xff, MP_QSTR_uzlib >> 8, 
    0x16, MP_QSTR_uzlib & 0xff, MP_QSTR_uzlib >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_upip_utarfile & 0xff, MP_QSTR_upip_utarfile >> 8, 
    0x16, MP_QSTR_tarfile & 0xff, MP_QSTR_tarfile >> 8, 
    0x11, MP_QSTR_gc & 0xff, MP_QSTR_gc >> 8, 
    0x14, MP_QSTR_collect & 0xff, MP_QSTR_collect >> 8, 
    0x36, 0x00, 
    0x59, 
    0x50, 
    0x17, MP_QSTR_debug & 0xff, MP_QSTR_debug >> 8, 
    0x23, 0x00, 
    0x23, 0x01, 
    0x2b, 0x02, 
    0x17, MP_QSTR_index_urls & 0xff, MP_QSTR_index_urls >> 8, 
    0x51, 
    0x17, MP_QSTR_install_path & 0xff, MP_QSTR_install_path >> 8, 
    0x2b, 0x00, 
    0x16, MP_QSTR_cleanup_files & 0xff, MP_QSTR_cleanup_files >> 8, 
    0x9f, 
    0x17, MP_QSTR_gzdict_sz & 0xff, MP_QSTR_gzdict_sz >> 8, 
    0x11, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0x22, 0x84, 0x00, 
    0x34, 0x01, 
    0x17, MP_QSTR_file_buf & 0xff, MP_QSTR_file_buf >> 8, 
    0x54, 
    0x32, 0x02, 
    0x10, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8, 
    0x11, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8, 
    0x34, 0x03, 
    0x16, MP_QSTR_NotFoundError & 0xff, MP_QSTR_NotFoundError >> 8, 
    0x32, 0x03, 
    0x16, MP_QSTR_op_split & 0xff, MP_QSTR_op_split >> 8, 
    0x32, 0x04, 
    0x16, MP_QSTR_op_basename & 0xff, MP_QSTR_op_basename >> 8, 
    0x22, 0x83, 0x7f, 
    0x2a, 0x01, 
    0x53, 
    0x33, 0x05, 
    0x16, MP_QSTR__makedirs & 0xff, MP_QSTR__makedirs >> 8, 
    0x32, 0x06, 
    0x16, MP_QSTR_save_file & 0xff, MP_QSTR_save_file >> 8, 
    0x32, 0x07, 
    0x16, MP_QSTR_install_tar & 0xff, MP_QSTR_install_tar >> 8, 
    0x32, 0x08, 
    0x16, MP_QSTR_expandhome & 0xff, MP_QSTR_expandhome >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_ussl & 0xff, MP_QSTR_ussl >> 8, 
    0x16, MP_QSTR_ussl & 0xff, MP_QSTR_ussl >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8, 
    0x16, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8, 
    0x52, 
    0x17, MP_QSTR_warn_ussl & 0xff, MP_QSTR_warn_ussl >> 8, 
    0x32, 0x09, 
    0x16, MP_QSTR_url_open & 0xff, MP_QSTR_url_open >> 8, 
    0x32, 0x0a, 
    0x16, MP_QSTR_get_pkg_metadata & 0xff, MP_QSTR_get_pkg_metadata >> 8, 
    0x51, 
    0x2a, 0x01, 
    0x53, 
    0x33, 0x0b, 
    0x16, MP_QSTR_fatal & 0xff, MP_QSTR_fatal >> 8, 
    0x32, 0x0c, 
    0x16, MP_QSTR_install_pkg & 0xff, MP_QSTR_install_pkg >> 8, 
    0x51, 
    0x2a, 0x01, 
    0x53, 
    0x33, 0x0d, 
    0x16, MP_QSTR_install & 0xff, MP_QSTR_install >> 8, 
    0x32, 0x0e, 
    0x16, MP_QSTR_get_install_path & 0xff, MP_QSTR_get_install_path >> 8, 
    0x32, 0x0f, 
    0x16, MP_QSTR_cleanup & 0xff, MP_QSTR_cleanup >> 8, 
    0x32, 0x10, 
    0x16, MP_QSTR_help & 0xff, MP_QSTR_help >> 8, 
    0x32, 0x11, 
    0x16, MP_QSTR_main & 0xff, MP_QSTR_main >> 8, 
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x10, MP_QSTR___main__ & 0xff, MP_QSTR___main__ >> 8, 
    0xd9, 
    0x44, 0x06, 0x80, 
    0x11, MP_QSTR_main & 0xff, MP_QSTR_main >> 8, 
    0x34, 0x00, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__0 = {{&mp_type_str}, 58328, 26, (const byte*)"\x68\x74\x74\x70\x73\x3a\x2f\x2f\x6d\x69\x63\x72\x6f\x70\x79\x74\x68\x6f\x6e\x2e\x6f\x72\x67\x2f\x70\x69"};
STATIC const mp_obj_str_t const_obj_upip__lt_module_gt__1 = {{&mp_type_str}, 3759, 21, (const byte*)"\x68\x74\x74\x70\x73\x3a\x2f\x2f\x70\x79\x70\x69\x2e\x6f\x72\x67\x2f\x70\x79\x70\x69"};
STATIC const mp_rom_obj_t const_table_data_upip__lt_module_gt_[18] = {
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__0),
    MP_ROM_PTR(&const_obj_upip__lt_module_gt__1),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__NotFoundError),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__op_split),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__op_basename),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt___makedirs),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__save_file),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__install_tar),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__expandhome),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__url_open),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__get_pkg_metadata),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__fatal),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__install_pkg),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__install),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__get_install_path),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__cleanup),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__help),
    MP_ROM_PTR(&raw_code_upip__lt_module_gt__main),
};
const mp_raw_code_t raw_code_upip__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_upip__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 301,
    .n_obj = 2,
    .n_raw_code = 16,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_upip_dot_py,
        .line_info = fun_data_upip__lt_module_gt_ + 0,
        .opcodes = fun_data_upip__lt_module_gt_ + 58,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__roundup
STATIC const byte fun_data_upip_utarfile__lt_module_gt__roundup[20] = {
    0x22, 0x0e,
    MP_QSTR_roundup & 0xff, MP_QSTR_roundup >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x0c, 0x00,
    0xb0, 
    0xb1, 
    0xf2, 
    0x81, 
    0xf3, 
    0xb1, 
    0x81, 
    0xf3, 
    0xd2, 
    0xef, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__roundup[2] = {
    MP_ROM_QSTR(MP_QSTR_val),
    MP_ROM_QSTR(MP_QSTR_align),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__roundup = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__roundup,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__roundup,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 20,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_roundup,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__roundup + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__roundup + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection___init__
STATIC const byte fun_data_upip_utarfile__lt_module_gt__FileSection___init__[31] = {
    0xa8, 0x04, 0x12,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x11, 0x25, 0x25, 0x00,
    0xb1, 
    0xb0, 
    0x18, MP_QSTR_f & 0xff, MP_QSTR_f >> 8, 
    0xb2, 
    0xb0, 
    0x18, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xb3, 
    0xb2, 
    0xf3, 
    0xb0, 
    0x18, MP_QSTR_align & 0xff, MP_QSTR_align >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection___init__[4] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_f),
    MP_ROM_QSTR(MP_QSTR_content_len),
    MP_ROM_QSTR(MP_QSTR_aligned_len),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 4,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__FileSection___init__,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection___init__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 31,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___init__,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__FileSection___init__ + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__FileSection___init__ + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection_read
STATIC const byte fun_data_upip_utarfile__lt_module_gt__FileSection_read[74] = {
    0xaa, 0x01, 0x1c,
    MP_QSTR_read & 0xff, MP_QSTR_read >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x16, 0x29, 0x23, 0x29, 0x25, 0x2b, 0x27, 0x2b, 0x00,
    0xb0, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0x80, 
    0xd9, 
    0x44, 0x03, 0x80, 
    0x23, 0x02, 
    0x63, 
    0xb1, 
    0xb0, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xd8, 
    0x44, 0x05, 0x80, 
    0xb0, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xc1, 
    0xb0, 
    0x13, MP_QSTR_f & 0xff, MP_QSTR_f >> 8, 
    0x14, MP_QSTR_read & 0xff, MP_QSTR_read >> 8, 
    0xb1, 
    0x36, 0x01, 
    0xc2, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0xb2, 
    0x34, 0x01, 
    0xc1, 
    0xb0, 
    0x57, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xb1, 
    0xe6, 
    0x5a, 
    0x18, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xb2, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip_utarfile__lt_module_gt__FileSection_read_0 = {{&mp_type_bytes}, 5381, 0, (const byte*)""};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection_read[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_sz),
    MP_ROM_PTR(&const_obj_upip_utarfile__lt_module_gt__FileSection_read_0),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection_read = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__FileSection_read,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection_read,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 74,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name = MP_QSTR_read,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__FileSection_read + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__FileSection_read + 17,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection_readinto
STATIC const byte fun_data_upip_utarfile__lt_module_gt__FileSection_readinto[79] = {
    0x2a, 0x1a,
    MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x20, 0x29, 0x22, 0x2e, 0x2f, 0x2b, 0x2b, 0x00,
    0xb0, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0x80, 
    0xd9, 
    0x44, 0x02, 0x80, 
    0x80, 
    0x63, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0xb1, 
    0x34, 0x01, 
    0xb0, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xd8, 
    0x44, 0x0f, 0x80, 
    0x12, MP_QSTR_memoryview & 0xff, MP_QSTR_memoryview >> 8, 
    0xb1, 
    0x34, 0x01, 
    0x51, 
    0xb0, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0x2e, 0x02, 
    0x55, 
    0xc1, 
    0xb0, 
    0x13, MP_QSTR_f & 0xff, MP_QSTR_f >> 8, 
    0x14, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8, 
    0xb1, 
    0x36, 0x01, 
    0xc2, 
    0xb0, 
    0x57, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xb2, 
    0xe6, 
    0x5a, 
    0x18, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xb2, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection_readinto[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection_readinto = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__FileSection_readinto,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection_readinto,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 79,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_readinto,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__FileSection_readinto + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__FileSection_readinto + 15,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection_skip
STATIC const byte fun_data_upip_utarfile__lt_module_gt__FileSection_skip[69] = {
    0x39, 0x1a,
    MP_QSTR_skip & 0xff, MP_QSTR_skip >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x29, 0x2a, 0x24, 0x27, 0x23, 0x28, 0x2c, 0x00,
    0xb0, 
    0x13, MP_QSTR_content_len & 0xff, MP_QSTR_content_len >> 8, 
    0xb0, 
    0x13, MP_QSTR_align & 0xff, MP_QSTR_align >> 8, 
    0xf2, 
    0xc1, 
    0xb1, 
    0x44, 0x26, 0x80, 
    0x12, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0x90, 
    0x34, 0x01, 
    0xc2, 
    0x42, 0x18, 0x80, 
    0x12, MP_QSTR_min & 0xff, MP_QSTR_min >> 8, 
    0xb1, 
    0x90, 
    0x34, 0x02, 
    0xc3, 
    0xb0, 
    0x13, MP_QSTR_f & 0xff, MP_QSTR_f >> 8, 
    0x14, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8, 
    0xb2, 
    0xb3, 
    0x36, 0x02, 
    0x59, 
    0xb1, 
    0xb3, 
    0xe6, 
    0xc1, 
    0xb1, 
    0x43, 0xe4, 0x7f, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection_skip[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection_skip = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__FileSection_skip,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection_skip,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 69,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_skip,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__FileSection_skip + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__FileSection_skip + 15,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__FileSection
STATIC const byte fun_data_upip_utarfile__lt_module_gt__FileSection[56] = {
    0x08, 0x1a,
    MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x8c, 0x10, 0x65, 0x40, 0x8c, 0x0a, 0x85, 0x09, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8, 
    0x22, 0x84, 0x80, 0x00, 
    0x2a, 0x01, 
    0x53, 
    0x33, 0x01, 
    0x16, MP_QSTR_read & 0xff, MP_QSTR_read >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8, 
    0x32, 0x03, 
    0x16, MP_QSTR_skip & 0xff, MP_QSTR_skip >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__FileSection[4] = {
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection___init__),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection_read),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection_readinto),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection_skip),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__FileSection = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__FileSection,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__FileSection,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 56,
    .n_obj = 0,
    .n_raw_code = 4,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_FileSection,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__FileSection + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__FileSection + 15,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarInfo___str__
STATIC const byte fun_data_upip_utarfile__lt_module_gt__TarInfo___str__[27] = {
    0x21, 0x0e,
    MP_QSTR___str__ & 0xff, MP_QSTR___str__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x34, 0x00,
    0x23, 0x01, 
    0xb0, 
    0x13, MP_QSTR_name & 0xff, MP_QSTR_name >> 8, 
    0xb0, 
    0x13, MP_QSTR_type & 0xff, MP_QSTR_type >> 8, 
    0xb0, 
    0x13, MP_QSTR_size & 0xff, MP_QSTR_size >> 8, 
    0x2a, 0x03, 
    0xf8, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_upip_utarfile__lt_module_gt__TarInfo___str___0 = {{&mp_type_str}, 62189, 19, (const byte*)"\x54\x61\x72\x49\x6e\x66\x6f\x28\x25\x72\x2c\x20\x25\x73\x2c\x20\x25\x64\x29"};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarInfo___str__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_PTR(&const_obj_upip_utarfile__lt_module_gt__TarInfo___str___0),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarInfo___str__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__TarInfo___str__,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarInfo___str__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 27,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___str__,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__TarInfo___str__ + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__TarInfo___str__ + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarInfo
STATIC const byte fun_data_upip_utarfile__lt_module_gt__TarInfo[28] = {
    0x00, 0x0e,
    MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x8c, 0x33, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR___str__ & 0xff, MP_QSTR___str__ >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarInfo[1] = {
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarInfo___str__),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarInfo = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__TarInfo,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarInfo,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 28,
    .n_obj = 0,
    .n_raw_code = 1,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_TarInfo,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__TarInfo + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__TarInfo + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile___init__
STATIC const byte fun_data_upip_utarfile__lt_module_gt__TarFile___init__[46] = {
    0xab, 0x80, 0x01, 0x14,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x39, 0x24, 0x48, 0x2d, 0x00,
    0xb2, 
    0x44, 0x08, 0x80, 
    0xb2, 
    0xb0, 
    0x18, MP_QSTR_f & 0xff, MP_QSTR_f >> 8, 
    0x42, 0x0d, 0x80, 
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0xb1, 
    0x10, MP_QSTR_rb & 0xff, MP_QSTR_rb >> 8, 
    0x34, 0x02, 
    0xb0, 
    0x18, MP_QSTR_f & 0xff, MP_QSTR_f >> 8, 
    0x51, 
    0xb0, 
    0x18, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile___init__[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_name),
    MP_ROM_QSTR(MP_QSTR_fileobj),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__TarFile___init__,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile___init__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 46,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name = MP_QSTR___init__,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__TarFile___init__ + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__TarFile___init__ + 14,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile_next
STATIC const byte fun_data_upip_utarfile__lt_module_gt__TarFile_next[207] = {
    0x49, 0x2a,
    MP_QSTR_next & 0xff, MP_QSTR_next >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x40, 0x27, 0x2a, 0x2d, 0x24, 0x42, 0x7b, 0x2b, 0x42, 0x26, 0x38, 0x33, 0x37, 0x1f, 0x23, 0x00,
    0xb0, 
    0x13, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8, 
    0x44, 0x0a, 0x80, 
    0xb0, 
    0x13, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8, 
    0x14, MP_QSTR_skip & 0xff, MP_QSTR_skip >> 8, 
    0x36, 0x00, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_f & 0xff, MP_QSTR_f >> 8, 
    0x14, MP_QSTR_read & 0xff, MP_QSTR_read >> 8, 
    0x22, 0x84, 0x00, 
    0x36, 0x01, 
    0xc1, 
    0xb1, 
    0x43, 0x02, 0x80, 
    0x51, 
    0x63, 
    0x12, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x14, MP_QSTR_struct & 0xff, MP_QSTR_struct >> 8, 
    0x12, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x14, MP_QSTR_addressof & 0xff, MP_QSTR_addressof >> 8, 
    0xb1, 
    0x36, 0x01, 
    0x12, MP_QSTR_TAR_HEADER & 0xff, MP_QSTR_TAR_HEADER >> 8, 
    0x12, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x13, MP_QSTR_LITTLE_ENDIAN & 0xff, MP_QSTR_LITTLE_ENDIAN >> 8, 
    0x36, 0x03, 
    0xc2, 
    0xb2, 
    0x13, MP_QSTR_name & 0xff, MP_QSTR_name >> 8, 
    0x80, 
    0x55, 
    0x80, 
    0xd9, 
    0x44, 0x02, 0x80, 
    0x51, 
    0x63, 
    0x12, MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8, 
    0x34, 0x00, 
    0xc3, 
    0x12, MP_QSTR_str & 0xff, MP_QSTR_str >> 8, 
    0xb2, 
    0x13, MP_QSTR_name & 0xff, MP_QSTR_name >> 8, 
    0x10, MP_QSTR_utf_hyphen_8 & 0xff, MP_QSTR_utf_hyphen_8 >> 8, 
    0x34, 0x02, 
    0x14, MP_QSTR_rstrip & 0xff, MP_QSTR_rstrip >> 8, 
    0x10, MP_QSTR__0x00_ & 0xff, MP_QSTR__0x00_ >> 8, 
    0x36, 0x01, 
    0xb3, 
    0x18, MP_QSTR_name & 0xff, MP_QSTR_name >> 8, 
    0x12, MP_QSTR_int & 0xff, MP_QSTR_int >> 8, 
    0x12, MP_QSTR_bytes & 0xff, MP_QSTR_bytes >> 8, 
    0xb2, 
    0x13, MP_QSTR_size & 0xff, MP_QSTR_size >> 8, 
    0x34, 0x01, 
    0x88, 
    0x34, 0x02, 
    0xb3, 
    0x18, MP_QSTR_size & 0xff, MP_QSTR_size >> 8, 
    0x12, MP_QSTR_REGTYPE & 0xff, MP_QSTR_REGTYPE >> 8, 
    0x12, MP_QSTR_DIRTYPE & 0xff, MP_QSTR_DIRTYPE >> 8, 
    0x2b, 0x02, 
    0xb3, 
    0x13, MP_QSTR_name & 0xff, MP_QSTR_name >> 8, 
    0x7f, 
    0x55, 
    0x10, MP_QSTR__slash_ & 0xff, MP_QSTR__slash_ >> 8, 
    0xd9, 
    0x55, 
    0xb3, 
    0x18, MP_QSTR_type & 0xff, MP_QSTR_type >> 8, 
    0x12, MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8, 
    0xb0, 
    0x13, MP_QSTR_f & 0xff, MP_QSTR_f >> 8, 
    0xb3, 
    0x13, MP_QSTR_size & 0xff, MP_QSTR_size >> 8, 
    0x12, MP_QSTR_roundup & 0xff, MP_QSTR_roundup >> 8, 
    0xb3, 
    0x13, MP_QSTR_size & 0xff, MP_QSTR_size >> 8, 
    0x22, 0x84, 0x00, 
    0x34, 0x02, 
    0x34, 0x03, 
    0x57, 
    0xb0, 
    0x18, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8, 
    0xb3, 
    0x18, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8, 
    0xb3, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile_next[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile_next = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__TarFile_next,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile_next,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 207,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_next,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__TarFile_next + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__TarFile_next + 23,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile___iter__
STATIC const byte fun_data_upip_utarfile__lt_module_gt__TarFile___iter__[11] = {
    0x09, 0x0e,
    MP_QSTR___iter__ & 0xff, MP_QSTR___iter__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x54, 0x00,
    0xb0, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile___iter__[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile___iter__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__TarFile___iter__,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile___iter__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___iter__,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__TarFile___iter__ + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__TarFile___iter__ + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile___next__
STATIC const byte fun_data_upip_utarfile__lt_module_gt__TarFile___next__[31] = {
    0x19, 0x14,
    MP_QSTR___next__ & 0xff, MP_QSTR___next__ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x57, 0x27, 0x26, 0x24, 0x00,
    0xb0, 
    0x14, MP_QSTR_next & 0xff, MP_QSTR_next >> 8, 
    0x36, 0x00, 
    0xc1, 
    0xb1, 
    0x51, 
    0xde, 
    0x44, 0x04, 0x80, 
    0x12, MP_QSTR_StopIteration & 0xff, MP_QSTR_StopIteration >> 8, 
    0x65, 
    0xb1, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile___next__[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile___next__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__TarFile___next__,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile___next__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 31,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___next__,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__TarFile___next__ + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__TarFile___next__ + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile_extractfile
STATIC const byte fun_data_upip_utarfile__lt_module_gt__TarFile_extractfile[14] = {
    0x12, 0x0e,
    MP_QSTR_extractfile & 0xff, MP_QSTR_extractfile >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x80, 0x5d, 0x00,
    0xb1, 
    0x13, MP_QSTR_subf & 0xff, MP_QSTR_subf >> 8, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile_extractfile[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_tarinfo),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile_extractfile = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__TarFile_extractfile,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile_extractfile,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_extractfile,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__TarFile_extractfile + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__TarFile_extractfile + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile__lt_module_gt__TarFile
STATIC const byte fun_data_upip_utarfile__lt_module_gt__TarFile[60] = {
    0x08, 0x1c,
    MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x8c, 0x38, 0x8a, 0x07, 0x85, 0x14, 0x65, 0x65, 0x60, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x51, 
    0x51, 
    0x2a, 0x02, 
    0x53, 
    0x33, 0x00, 
    0x16, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_next & 0xff, MP_QSTR_next >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR___iter__ & 0xff, MP_QSTR___iter__ >> 8, 
    0x32, 0x03, 
    0x16, MP_QSTR___next__ & 0xff, MP_QSTR___next__ >> 8, 
    0x32, 0x04, 
    0x16, MP_QSTR_extractfile & 0xff, MP_QSTR_extractfile >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt__TarFile[5] = {
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile___init__),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile_next),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile___iter__),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile___next__),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile_extractfile),
};
STATIC const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt__TarFile = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip_utarfile__lt_module_gt__TarFile,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt__TarFile,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 60,
    .n_obj = 0,
    .n_raw_code = 5,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_TarFile,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt__TarFile + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt__TarFile + 16,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file upip_utarfile.py, scope upip_utarfile_<module>
STATIC const byte fun_data_upip_utarfile__lt_module_gt_[131] = {
    0x18, 0x20,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_upip_utarfile_dot_py & 0xff, MP_QSTR_upip_utarfile_dot_py >> 8,
    0x68, 0x22, 0x38, 0x7b, 0x26, 0x46, 0x65, 0x8b, 0x23, 0x6b, 0x40, 0x00,
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x16, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x2c, 0x02, 
    0x11, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x13, MP_QSTR_ARRAY & 0xff, MP_QSTR_ARRAY >> 8, 
    0x80, 
    0xed, 
    0x11, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x13, MP_QSTR_UINT8 & 0xff, MP_QSTR_UINT8 >> 8, 
    0x22, 0x80, 0x64, 
    0xed, 
    0x2a, 0x02, 
    0x10, MP_QSTR_name & 0xff, MP_QSTR_name >> 8, 
    0x62, 
    0x11, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x13, MP_QSTR_ARRAY & 0xff, MP_QSTR_ARRAY >> 8, 
    0x22, 0x80, 0x7c, 
    0xed, 
    0x11, MP_QSTR_uctypes & 0xff, MP_QSTR_uctypes >> 8, 
    0x13, MP_QSTR_UINT8 & 0xff, MP_QSTR_UINT8 >> 8, 
    0x8b, 
    0xed, 
    0x2a, 0x02, 
    0x10, MP_QSTR_size & 0xff, MP_QSTR_size >> 8, 
    0x62, 
    0x16, MP_QSTR_TAR_HEADER & 0xff, MP_QSTR_TAR_HEADER >> 8, 
    0x10, MP_QSTR_dir & 0xff, MP_QSTR_dir >> 8, 
    0x16, MP_QSTR_DIRTYPE & 0xff, MP_QSTR_DIRTYPE >> 8, 
    0x10, MP_QSTR_file & 0xff, MP_QSTR_file >> 8, 
    0x16, MP_QSTR_REGTYPE & 0xff, MP_QSTR_REGTYPE >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR_roundup & 0xff, MP_QSTR_roundup >> 8, 
    0x54, 
    0x32, 0x01, 
    0x10, MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8, 
    0x34, 0x02, 
    0x16, MP_QSTR_FileSection & 0xff, MP_QSTR_FileSection >> 8, 
    0x54, 
    0x32, 0x02, 
    0x10, MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8, 
    0x34, 0x02, 
    0x16, MP_QSTR_TarInfo & 0xff, MP_QSTR_TarInfo >> 8, 
    0x54, 
    0x32, 0x03, 
    0x10, MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8, 
    0x34, 0x02, 
    0x16, MP_QSTR_TarFile & 0xff, MP_QSTR_TarFile >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_upip_utarfile__lt_module_gt_[4] = {
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__roundup),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__FileSection),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarInfo),
    MP_ROM_PTR(&raw_code_upip_utarfile__lt_module_gt__TarFile),
};
const mp_raw_code_t raw_code_upip_utarfile__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_upip_utarfile__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_upip_utarfile__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 131,
    .n_obj = 0,
    .n_raw_code = 4,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_upip_utarfile_dot_py,
        .line_info = fun_data_upip_utarfile__lt_module_gt_ + 0,
        .opcodes = fun_data_upip_utarfile__lt_module_gt_ + 18,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ntptime.py, scope ntptime__lt_module_gt__time
STATIC const byte fun_data_ntptime__lt_module_gt__time[135] = {
    0x64, 0x22,
    MP_QSTR_time & 0xff, MP_QSTR_time >> 8,
    MP_QSTR_ntptime_dot_py & 0xff, MP_QSTR_ntptime_dot_py >> 8,
    0x80, 0x10, 0x28, 0x24, 0x33, 0x35, 0x23, 0x28, 0x29, 0x4a, 0x28, 0x34, 0x00,
    0x12, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0x22, 0x30, 
    0x34, 0x01, 
    0xc0, 
    0x9b, 
    0xb0, 
    0x80, 
    0x56, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x14, MP_QSTR_getaddrinfo & 0xff, MP_QSTR_getaddrinfo >> 8, 
    0x12, MP_QSTR_host & 0xff, MP_QSTR_host >> 8, 
    0x22, 0x80, 0x7b, 
    0x36, 0x02, 
    0x80, 
    0x55, 
    0x7f, 
    0x55, 
    0xc1, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x14, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x13, MP_QSTR_AF_INET & 0xff, MP_QSTR_AF_INET >> 8, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x13, MP_QSTR_SOCK_DGRAM & 0xff, MP_QSTR_SOCK_DGRAM >> 8, 
    0x36, 0x02, 
    0xc2, 
    0x49, 0x1b, 0x00, 
    0xb2, 
    0x14, MP_QSTR_settimeout & 0xff, MP_QSTR_settimeout >> 8, 
    0x81, 
    0x36, 0x01, 
    0x59, 
    0xb2, 
    0x14, MP_QSTR_sendto & 0xff, MP_QSTR_sendto >> 8, 
    0xb0, 
    0xb1, 
    0x36, 0x02, 
    0xc3, 
    0xb2, 
    0x14, MP_QSTR_recv & 0xff, MP_QSTR_recv >> 8, 
    0x22, 0x30, 
    0x36, 0x01, 
    0xc4, 
    0x51, 
    0xb2, 
    0x14, MP_QSTR_close & 0xff, MP_QSTR_close >> 8, 
    0x36, 0x00, 
    0x59, 
    0x5d, 
    0x12, MP_QSTR_struct & 0xff, MP_QSTR_struct >> 8, 
    0x14, MP_QSTR_unpack & 0xff, MP_QSTR_unpack >> 8, 
    0x10, MP_QSTR__bang_I & 0xff, MP_QSTR__bang_I >> 8, 
    0xb4, 
    0xa8, 
    0xac, 
    0x2e, 0x02, 
    0x55, 
    0x36, 0x02, 
    0x80, 
    0x55, 
    0xc5, 
    0xb5, 
    0x12, MP_QSTR_NTP_DELTA & 0xff, MP_QSTR_NTP_DELTA >> 8, 
    0xf3, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_ntptime__lt_module_gt__time = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_ntptime__lt_module_gt__time,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 135,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_time,
        .qstr_source_file = MP_QSTR_ntptime_dot_py,
        .line_info = fun_data_ntptime__lt_module_gt__time + 0,
        .opcodes = fun_data_ntptime__lt_module_gt__time + 19,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ntptime.py, scope ntptime__lt_module_gt__settime
STATIC const byte fun_data_ntptime__lt_module_gt__settime[79] = {
    0x68, 0x16,
    MP_QSTR_settime & 0xff, MP_QSTR_settime >> 8,
    MP_QSTR_ntptime_dot_py & 0xff, MP_QSTR_ntptime_dot_py >> 8,
    0x80, 0x20, 0x26, 0x26, 0x26, 0x28, 0x00,
    0x12, MP_QSTR_time & 0xff, MP_QSTR_time >> 8, 
    0x34, 0x00, 
    0xc0, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_machine & 0xff, MP_QSTR_machine >> 8, 
    0xc1, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_utime & 0xff, MP_QSTR_utime >> 8, 
    0xc2, 
    0xb2, 
    0x14, MP_QSTR_localtime & 0xff, MP_QSTR_localtime >> 8, 
    0xb0, 
    0x36, 0x01, 
    0xc3, 
    0xb1, 
    0x14, MP_QSTR_RTC & 0xff, MP_QSTR_RTC >> 8, 
    0x36, 0x00, 
    0x14, MP_QSTR_datetime & 0xff, MP_QSTR_datetime >> 8, 
    0xb3, 
    0x80, 
    0x55, 
    0xb3, 
    0x81, 
    0x55, 
    0xb3, 
    0x82, 
    0x55, 
    0xb3, 
    0x86, 
    0x55, 
    0x81, 
    0xf2, 
    0xb3, 
    0x83, 
    0x55, 
    0xb3, 
    0x84, 
    0x55, 
    0xb3, 
    0x85, 
    0x55, 
    0x80, 
    0x2a, 0x08, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_ntptime__lt_module_gt__settime = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_ntptime__lt_module_gt__settime,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 79,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 14,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_settime,
        .qstr_source_file = MP_QSTR_ntptime_dot_py,
        .line_info = fun_data_ntptime__lt_module_gt__settime + 0,
        .opcodes = fun_data_ntptime__lt_module_gt__settime + 13,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ntptime.py, scope ntptime_<module>
STATIC const byte fun_data_ntptime__lt_module_gt_[93] = {
    0x24, 0x1e,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_ntptime_dot_py & 0xff, MP_QSTR_ntptime_dot_py >> 8,
    0x23, 0x4c, 0x2c, 0x23, 0x4c, 0x6c, 0x65, 0x45, 0x85, 0x10, 0x00,
    0x48, 0x0b, 0x00, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_usocket & 0xff, MP_QSTR_usocket >> 8, 
    0x16, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x4a, 0x0d, 0x00, 
    0x59, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x16, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x48, 0x0b, 0x00, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_ustruct & 0xff, MP_QSTR_ustruct >> 8, 
    0x16, MP_QSTR_struct & 0xff, MP_QSTR_struct >> 8, 
    0x4a, 0x0d, 0x00, 
    0x59, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_struct & 0xff, MP_QSTR_struct >> 8, 
    0x16, MP_QSTR_struct & 0xff, MP_QSTR_struct >> 8, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x23, 0x00, 
    0x16, MP_QSTR_NTP_DELTA & 0xff, MP_QSTR_NTP_DELTA >> 8, 
    0x23, 0x01, 
    0x16, MP_QSTR_host & 0xff, MP_QSTR_host >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR_time & 0xff, MP_QSTR_time >> 8, 
    0x32, 0x03, 
    0x16, MP_QSTR_settime & 0xff, MP_QSTR_settime >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_int_t const_obj_ntptime__lt_module_gt__0 = {{&mp_type_int}, {.neg=0, .fixed_dig=1, .alloc=2, .len=2, .dig=(uint16_t*)(const uint16_t[]){0xc200,0xbc17}}};
STATIC const mp_obj_str_t const_obj_ntptime__lt_module_gt__1 = {{&mp_type_str}, 33769, 12, (const byte*)"\x70\x6f\x6f\x6c\x2e\x6e\x74\x70\x2e\x6f\x72\x67"};
STATIC const mp_rom_obj_t const_table_data_ntptime__lt_module_gt_[4] = {
    MP_ROM_PTR(&const_obj_ntptime__lt_module_gt__0),
    MP_ROM_PTR(&const_obj_ntptime__lt_module_gt__1),
    MP_ROM_PTR(&raw_code_ntptime__lt_module_gt__time),
    MP_ROM_PTR(&raw_code_ntptime__lt_module_gt__settime),
};
const mp_raw_code_t raw_code_ntptime__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_ntptime__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_ntptime__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 93,
    .n_obj = 2,
    .n_raw_code = 2,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_ntptime_dot_py,
        .line_info = fun_data_ntptime__lt_module_gt_ + 0,
        .opcodes = fun_data_ntptime__lt_module_gt_ + 17,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHTBase___init__
STATIC const byte fun_data_dht__lt_module_gt__DHTBase___init__[27] = {
    0x1a, 0x10,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x80, 0x0a, 0x25, 0x00,
    0xb1, 
    0xb0, 
    0x18, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0x12, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0x85, 
    0x34, 0x01, 
    0xb0, 
    0x18, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHTBase___init__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_pin),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHTBase___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_dht__lt_module_gt__DHTBase___init__,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHTBase___init__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 27,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___init__,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHTBase___init__ + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHTBase___init__ + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHTBase_measure
STATIC const byte fun_data_dht__lt_module_gt__DHTBase_measure[64] = {
    0x21, 0x14,
    MP_QSTR_measure & 0xff, MP_QSTR_measure >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x80, 0x0e, 0x25, 0x2b, 0x3a, 0x00,
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0xc1, 
    0x12, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0xb1, 
    0x34, 0x02, 
    0x59, 
    0xb1, 
    0x80, 
    0x55, 
    0xb1, 
    0x81, 
    0x55, 
    0xf2, 
    0xb1, 
    0x82, 
    0x55, 
    0xf2, 
    0xb1, 
    0x83, 
    0x55, 
    0xf2, 
    0x22, 0x81, 0x7f, 
    0xef, 
    0xb1, 
    0x84, 
    0x55, 
    0xdc, 
    0x44, 0x08, 0x80, 
    0x12, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8, 
    0x23, 0x01, 
    0x34, 0x01, 
    0x65, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_dht__lt_module_gt__DHTBase_measure_0 = {{&mp_type_str}, 53040, 14, (const byte*)"\x63\x68\x65\x63\x6b\x73\x75\x6d\x20\x65\x72\x72\x6f\x72"};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHTBase_measure[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_PTR(&const_obj_dht__lt_module_gt__DHTBase_measure_0),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHTBase_measure = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_dht__lt_module_gt__DHTBase_measure,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHTBase_measure,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 64,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_measure,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHTBase_measure + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHTBase_measure + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHTBase
STATIC const byte fun_data_dht__lt_module_gt__DHTBase[35] = {
    0x00, 0x12,
    MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x8c, 0x09, 0x65, 0x20, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_measure & 0xff, MP_QSTR_measure >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHTBase[2] = {
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHTBase___init__),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHTBase_measure),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHTBase = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_dht__lt_module_gt__DHTBase,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHTBase,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_obj = 0,
    .n_raw_code = 2,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_DHTBase,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHTBase + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHTBase + 11,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT11_humidity
STATIC const byte fun_data_dht__lt_module_gt__DHT11_humidity[16] = {
    0x11, 0x0e,
    MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x80, 0x15, 0x00,
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x80, 
    0x55, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT11_humidity[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT11_humidity = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_dht__lt_module_gt__DHT11_humidity,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT11_humidity,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_humidity,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHT11_humidity + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHT11_humidity + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT11_temperature
STATIC const byte fun_data_dht__lt_module_gt__DHT11_temperature[16] = {
    0x11, 0x0e,
    MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x80, 0x18, 0x00,
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x82, 
    0x55, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT11_temperature[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT11_temperature = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_dht__lt_module_gt__DHT11_temperature,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT11_temperature,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_temperature,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHT11_temperature + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHT11_temperature + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT11
STATIC const byte fun_data_dht__lt_module_gt__DHT11[34] = {
    0x00, 0x10,
    MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x8c, 0x14, 0x65, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT11[2] = {
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT11_humidity),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT11_temperature),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT11 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_dht__lt_module_gt__DHT11,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT11,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 34,
    .n_obj = 0,
    .n_raw_code = 2,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_DHT11,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHT11 + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHT11 + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT22_humidity
STATIC const byte fun_data_dht__lt_module_gt__DHT22_humidity[28] = {
    0x19, 0x0e,
    MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x80, 0x1c, 0x00,
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x80, 
    0x55, 
    0x88, 
    0xf0, 
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x81, 
    0x55, 
    0xed, 
    0x23, 0x01, 
    0xf4, 
    0x63, 
};
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
STATIC const mp_obj_float_t const_obj_dht__lt_module_gt__DHT22_humidity_0 = {{&mp_type_float}, 0.1};
#endif
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT22_humidity[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
    MP_ROM_PTR(&const_obj_dht__lt_module_gt__DHT22_humidity_0),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_C
    (mp_rom_obj_t)(0xbe4cccce),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_D
    (mp_rom_obj_t)(0xbfbd99999999999a),
#endif
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT22_humidity = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_dht__lt_module_gt__DHT22_humidity,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT22_humidity,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 28,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_humidity,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHT22_humidity + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHT22_humidity + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT22_temperature
STATIC const byte fun_data_dht__lt_module_gt__DHT22_temperature[53] = {
    0x21, 0x14,
    MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x80, 0x1f, 0x37, 0x2d, 0x23, 0x00,
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x82, 
    0x55, 
    0x22, 0x80, 0x7f, 
    0xef, 
    0x88, 
    0xf0, 
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x83, 
    0x55, 
    0xed, 
    0x23, 0x01, 
    0xf4, 
    0xc1, 
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x82, 
    0x55, 
    0x22, 0x81, 0x00, 
    0xef, 
    0x44, 0x03, 0x80, 
    0xb1, 
    0xd1, 
    0xc1, 
    0xb1, 
    0x63, 
};
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
STATIC const mp_obj_float_t const_obj_dht__lt_module_gt__DHT22_temperature_0 = {{&mp_type_float}, 0.1};
#endif
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT22_temperature[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
    MP_ROM_PTR(&const_obj_dht__lt_module_gt__DHT22_temperature_0),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_C
    (mp_rom_obj_t)(0xbe4cccce),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_D
    (mp_rom_obj_t)(0xbfbd99999999999a),
#endif
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT22_temperature = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_dht__lt_module_gt__DHT22_temperature,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT22_temperature,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 53,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_temperature,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHT22_temperature + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHT22_temperature + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht__lt_module_gt__DHT22
STATIC const byte fun_data_dht__lt_module_gt__DHT22[34] = {
    0x00, 0x10,
    MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x8c, 0x1b, 0x65, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR_humidity & 0xff, MP_QSTR_humidity >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_temperature & 0xff, MP_QSTR_temperature >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt__DHT22[2] = {
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT22_humidity),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT22_temperature),
};
STATIC const mp_raw_code_t raw_code_dht__lt_module_gt__DHT22 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_dht__lt_module_gt__DHT22,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt__DHT22,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 34,
    .n_obj = 0,
    .n_raw_code = 2,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_DHT22,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt__DHT22 + 0,
        .opcodes = fun_data_dht__lt_module_gt__DHT22 + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file dht.py, scope dht_<module>
STATIC const byte fun_data_dht__lt_module_gt_[99] = {
    0x24, 0x1a,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_dht_dot_py & 0xff, MP_QSTR_dht_dot_py >> 8,
    0x60, 0x23, 0x54, 0x54, 0x8b, 0x0b, 0x8e, 0x07, 0x00,
    0x48, 0x13, 0x00, 
    0x80, 
    0x10, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_esp & 0xff, MP_QSTR_esp >> 8, 
    0x1c, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8, 
    0x16, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8, 
    0x59, 
    0x4a, 0x15, 0x00, 
    0x59, 
    0x80, 
    0x10, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_pyb & 0xff, MP_QSTR_pyb >> 8, 
    0x1c, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8, 
    0x16, MP_QSTR_dht_readinto & 0xff, MP_QSTR_dht_readinto >> 8, 
    0x59, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x54, 
    0x32, 0x00, 
    0x10, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8, 
    0x34, 0x02, 
    0x16, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8, 
    0x54, 
    0x32, 0x01, 
    0x10, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8, 
    0x11, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8, 
    0x34, 0x03, 
    0x16, MP_QSTR_DHT11 & 0xff, MP_QSTR_DHT11 >> 8, 
    0x54, 
    0x32, 0x02, 
    0x10, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8, 
    0x11, MP_QSTR_DHTBase & 0xff, MP_QSTR_DHTBase >> 8, 
    0x34, 0x03, 
    0x16, MP_QSTR_DHT22 & 0xff, MP_QSTR_DHT22 >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_dht__lt_module_gt_[3] = {
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHTBase),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT11),
    MP_ROM_PTR(&raw_code_dht__lt_module_gt__DHT22),
};
const mp_raw_code_t raw_code_dht__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_dht__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_dht__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 99,
    .n_obj = 0,
    .n_raw_code = 3,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_dht_dot_py,
        .line_info = fun_data_dht__lt_module_gt_ + 0,
        .opcodes = fun_data_dht__lt_module_gt_ + 15,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DS18X20___init__
STATIC const byte fun_data_ds18x20__lt_module_gt__DS18X20___init__[27] = {
    0x1a, 0x10,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x80, 0x0b, 0x25, 0x00,
    0xb1, 
    0xb0, 
    0x18, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x12, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0x89, 
    0x34, 0x01, 
    0xb0, 
    0x18, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DS18X20___init__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_onewire),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DS18X20___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_ds18x20__lt_module_gt__DS18X20___init__,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DS18X20___init__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 27,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___init__,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt__DS18X20___init__ + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt__DS18X20___init__ + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DS18X20_scan_<listcomp>
STATIC const byte fun_data_ds18x20__lt_module_gt__DS18X20_scan__lt_listcomp_gt_[36] = {
    0x51, 0x0e,
    MP_QSTR__lt_listcomp_gt_ & 0xff, MP_QSTR__lt_listcomp_gt_ >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x80, 0x0f, 0x00,
    0x2b, 0x00, 
    0xb0, 
    0x5f, 
    0x4b, 0x13, 0x00, 
    0xc1, 
    0xb1, 
    0x80, 
    0x55, 
    0x90, 
    0xa2, 
    0xa8, 
    0x2a, 0x03, 
    0xdd, 
    0x44, 0xf0, 0x7f, 
    0xb1, 
    0x2f, 0x14, 
    0x42, 0xea, 0x7f, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DS18X20_scan__lt_listcomp_gt_[1] = {
    MP_ROM_QSTR(MP_QSTR__star_),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DS18X20_scan__lt_listcomp_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_ds18x20__lt_module_gt__DS18X20_scan__lt_listcomp_gt_,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DS18X20_scan__lt_listcomp_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 36,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_listcomp_gt_,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt__DS18X20_scan__lt_listcomp_gt_ + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt__DS18X20_scan__lt_listcomp_gt_ + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DS18X20_scan
STATIC const byte fun_data_ds18x20__lt_module_gt__DS18X20_scan[23] = {
    0x19, 0x0e,
    MP_QSTR_scan & 0xff, MP_QSTR_scan >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x80, 0x0f, 0x00,
    0x32, 0x01, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_scan & 0xff, MP_QSTR_scan >> 8, 
    0x36, 0x00, 
    0x34, 0x01, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DS18X20_scan[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DS18X20_scan__lt_listcomp_gt_),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DS18X20_scan = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_ds18x20__lt_module_gt__DS18X20_scan,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DS18X20_scan,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_obj = 0,
    .n_raw_code = 1,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_scan,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt__DS18X20_scan + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt__DS18X20_scan + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DS18X20_convert_temp
STATIC const byte fun_data_ds18x20__lt_module_gt__DS18X20_convert_temp[54] = {
    0x19, 0x12,
    MP_QSTR_convert_temp & 0xff, MP_QSTR_convert_temp >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x80, 0x12, 0x2b, 0x31, 0x00,
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8, 
    0x52, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x13, MP_QSTR_SKIP_ROM & 0xff, MP_QSTR_SKIP_ROM >> 8, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0x22, 0x80, 0x44, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DS18X20_convert_temp[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DS18X20_convert_temp = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_ds18x20__lt_module_gt__DS18X20_convert_temp,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DS18X20_convert_temp,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 54,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_convert_temp,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt__DS18X20_convert_temp + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt__DS18X20_convert_temp + 11,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DS18X20_read_scratch
STATIC const byte fun_data_ds18x20__lt_module_gt__DS18X20_read_scratch[94] = {
    0x22, 0x1a,
    MP_QSTR_read_scratch & 0xff, MP_QSTR_read_scratch >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x80, 0x17, 0x2b, 0x2b, 0x2d, 0x2e, 0x30, 0x29, 0x00,
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8, 
    0x52, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_select_rom & 0xff, MP_QSTR_select_rom >> 8, 
    0xb1, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0x22, 0x81, 0x3e, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8, 
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_crc8 & 0xff, MP_QSTR_crc8 >> 8, 
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x36, 0x01, 
    0x44, 0x09, 0x80, 
    0x12, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8, 
    0x10, MP_QSTR_CRC_space_error & 0xff, MP_QSTR_CRC_space_error >> 8, 
    0x34, 0x01, 
    0x65, 
    0xb0, 
    0x13, MP_QSTR_buf & 0xff, MP_QSTR_buf >> 8, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DS18X20_read_scratch[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_rom),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DS18X20_read_scratch = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_ds18x20__lt_module_gt__DS18X20_read_scratch,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DS18X20_read_scratch,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 94,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_read_scratch,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt__DS18X20_read_scratch + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt__DS18X20_read_scratch + 15,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DS18X20_write_scratch
STATIC const byte fun_data_ds18x20__lt_module_gt__DS18X20_write_scratch[60] = {
    0x2b, 0x14,
    MP_QSTR_write_scratch & 0xff, MP_QSTR_write_scratch >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x80, 0x20, 0x2b, 0x2b, 0x2d, 0x00,
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8, 
    0x52, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_select_rom & 0xff, MP_QSTR_select_rom >> 8, 
    0xb1, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0x22, 0x80, 0x4e, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x13, MP_QSTR_ow & 0xff, MP_QSTR_ow >> 8, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0xb2, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DS18X20_write_scratch[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_rom),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DS18X20_write_scratch = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .fun_data = fun_data_ds18x20__lt_module_gt__DS18X20_write_scratch,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DS18X20_write_scratch,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 60,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_write_scratch,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt__DS18X20_write_scratch + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt__DS18X20_write_scratch + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DS18X20_read_temp
STATIC const byte fun_data_ds18x20__lt_module_gt__DS18X20_read_temp[122] = {
    0x3a, 0x22,
    MP_QSTR_read_temp & 0xff, MP_QSTR_read_temp >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x80, 0x26, 0x28, 0x28, 0x26, 0x2a, 0x4d, 0x26, 0x51, 0x2a, 0x29, 0x2a, 0x00,
    0xb0, 
    0x14, MP_QSTR_read_scratch & 0xff, MP_QSTR_read_scratch >> 8, 
    0xb1, 
    0x36, 0x01, 
    0xc2, 
    0xb1, 
    0x80, 
    0x55, 
    0x90, 
    0xd9, 
    0x44, 0x34, 0x80, 
    0xb2, 
    0x81, 
    0x55, 
    0x44, 0x17, 0x80, 
    0xb2, 
    0x80, 
    0x55, 
    0x81, 
    0xf1, 
    0x22, 0x81, 0x00, 
    0xed, 
    0xc3, 
    0xb3, 
    0xd2, 
    0x81, 
    0xf2, 
    0x22, 0x81, 0x7f, 
    0xef, 
    0xd1, 
    0xc3, 
    0x42, 0x06, 0x80, 
    0xb2, 
    0x80, 
    0x55, 
    0x81, 
    0xf1, 
    0xc3, 
    0xb3, 
    0x23, 0x02, 
    0xf3, 
    0xb2, 
    0x87, 
    0x55, 
    0xb2, 
    0x86, 
    0x55, 
    0xf3, 
    0xb2, 
    0x87, 
    0x55, 
    0xf7, 
    0xf2, 
    0x63, 
    0xb2, 
    0x81, 
    0x55, 
    0x88, 
    0xf0, 
    0xb2, 
    0x80, 
    0x55, 
    0xed, 
    0xc3, 
    0xb3, 
    0x22, 0x82, 0x80, 0x00, 
    0xef, 
    0x44, 0x0a, 0x80, 
    0xb3, 
    0x22, 0x83, 0xff, 0x7f, 
    0xee, 
    0x81, 
    0xf2, 
    0xd1, 
    0xc3, 
    0xb3, 
    0x90, 
    0xf7, 
    0x63, 
    0x51, 
    0x63, 
};
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
STATIC const mp_obj_float_t const_obj_ds18x20__lt_module_gt__DS18X20_read_temp_0 = {{&mp_type_float}, 0.25};
#endif
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DS18X20_read_temp[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_rom),
#if MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_A || MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_B
    MP_ROM_PTR(&const_obj_ds18x20__lt_module_gt__DS18X20_read_temp_0),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_C
    (mp_rom_obj_t)(0xbf000002),
#elif MICROPY_OBJ_REPR == MICROPY_OBJ_REPR_D
    (mp_rom_obj_t)(0xbfd4000000000000),
#endif
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DS18X20_read_temp = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_ds18x20__lt_module_gt__DS18X20_read_temp,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DS18X20_read_temp,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 122,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_read_temp,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt__DS18X20_read_temp + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt__DS18X20_read_temp + 19,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20__lt_module_gt__DS18X20
STATIC const byte fun_data_ds18x20__lt_module_gt__DS18X20[62] = {
    0x00, 0x20,
    MP_QSTR_DS18X20 & 0xff, MP_QSTR_DS18X20 >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x8c, 0x0a, 0x65, 0x20, 0x65, 0x65, 0x40, 0x85, 0x09, 0x65, 0x60, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_DS18X20 & 0xff, MP_QSTR_DS18X20 >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_scan & 0xff, MP_QSTR_scan >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR_convert_temp & 0xff, MP_QSTR_convert_temp >> 8, 
    0x32, 0x03, 
    0x16, MP_QSTR_read_scratch & 0xff, MP_QSTR_read_scratch >> 8, 
    0x32, 0x04, 
    0x16, MP_QSTR_write_scratch & 0xff, MP_QSTR_write_scratch >> 8, 
    0x32, 0x05, 
    0x16, MP_QSTR_read_temp & 0xff, MP_QSTR_read_temp >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt__DS18X20[6] = {
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DS18X20___init__),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DS18X20_scan),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DS18X20_convert_temp),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DS18X20_read_scratch),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DS18X20_write_scratch),
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DS18X20_read_temp),
};
STATIC const mp_raw_code_t raw_code_ds18x20__lt_module_gt__DS18X20 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_ds18x20__lt_module_gt__DS18X20,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt__DS18X20,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 62,
    .n_obj = 0,
    .n_raw_code = 6,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_DS18X20,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt__DS18X20 + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt__DS18X20 + 18,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file ds18x20.py, scope ds18x20_<module>
STATIC const byte fun_data_ds18x20__lt_module_gt_[39] = {
    0x10, 0x10,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_ds18x20_dot_py & 0xff, MP_QSTR_ds18x20_dot_py >> 8,
    0x60, 0x70, 0x60, 0x00,
    0x80, 
    0x10, MP_QSTR_const & 0xff, MP_QSTR_const >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_micropython & 0xff, MP_QSTR_micropython >> 8, 
    0x1c, MP_QSTR_const & 0xff, MP_QSTR_const >> 8, 
    0x16, MP_QSTR_const & 0xff, MP_QSTR_const >> 8, 
    0x59, 
    0x54, 
    0x32, 0x00, 
    0x10, MP_QSTR_DS18X20 & 0xff, MP_QSTR_DS18X20 >> 8, 
    0x34, 0x02, 
    0x16, MP_QSTR_DS18X20 & 0xff, MP_QSTR_DS18X20 >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_ds18x20__lt_module_gt_[1] = {
    MP_ROM_PTR(&raw_code_ds18x20__lt_module_gt__DS18X20),
};
const mp_raw_code_t raw_code_ds18x20__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_ds18x20__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_ds18x20__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 39,
    .n_obj = 0,
    .n_raw_code = 1,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_ds18x20_dot_py,
        .line_info = fun_data_ds18x20__lt_module_gt_ + 0,
        .opcodes = fun_data_ds18x20__lt_module_gt_ + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWireError
STATIC const byte fun_data_onewire__lt_module_gt__OneWireError[23] = {
    0x00, 0x0e,
    MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x8c, 0x07, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWireError = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_onewire__lt_module_gt__OneWireError,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_OneWireError,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWireError + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWireError + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire___init__
STATIC const byte fun_data_onewire__lt_module_gt__OneWire___init__[35] = {
    0x2a, 0x10,
    MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x0f, 0x25, 0x00,
    0xb1, 
    0xb0, 
    0x18, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0x14, MP_QSTR_init & 0xff, MP_QSTR_init >> 8, 
    0xb1, 
    0x13, MP_QSTR_OPEN_DRAIN & 0xff, MP_QSTR_OPEN_DRAIN >> 8, 
    0xb1, 
    0x13, MP_QSTR_PULL_UP & 0xff, MP_QSTR_PULL_UP >> 8, 
    0x36, 0x02, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire___init__[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_pin),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire___init__ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire___init__,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire___init__,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR___init__,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire___init__ + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire___init__ + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_reset
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_reset[40] = {
    0xaa, 0x01, 0x14,
    MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x13, 0x2d, 0x28, 0x24, 0x00,
    0x12, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x14, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0x36, 0x01, 
    0xc2, 
    0xb1, 
    0x44, 0x08, 0x80, 
    0xb2, 
    0x43, 0x04, 0x80, 
    0x12, MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8, 
    0x65, 
    0xb2, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_reset[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_required),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_reset = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_reset,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_reset,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 40,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name = MP_QSTR_reset,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_reset + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_reset + 13,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_readbit
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_readbit[22] = {
    0x19, 0x0e,
    MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x19, 0x00,
    0x12, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x14, MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0x36, 0x01, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_readbit[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_readbit = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_readbit,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_readbit,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 22,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_readbit,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_readbit + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_readbit + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_readbyte
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_readbyte[22] = {
    0x19, 0x0e,
    MP_QSTR_readbyte & 0xff, MP_QSTR_readbyte >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x1c, 0x00,
    0x12, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x14, MP_QSTR_readbyte & 0xff, MP_QSTR_readbyte >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0x36, 0x01, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_readbyte[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_readbyte = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_readbyte,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_readbyte,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 22,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_readbyte,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_readbyte + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_readbyte + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_readinto
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_readinto[49] = {
    0x3a, 0x10,
    MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x1f, 0x2c, 0x00,
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0xb1, 
    0x34, 0x01, 
    0x80, 
    0x42, 0x13, 0x80, 
    0x57, 
    0xc2, 
    0x12, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x14, MP_QSTR_readbyte & 0xff, MP_QSTR_readbyte >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0x36, 0x01, 
    0xb1, 
    0xb2, 
    0x56, 
    0x81, 
    0xe5, 
    0x58, 
    0x5a, 
    0xd7, 
    0x43, 0xe7, 0x7f, 
    0x59, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_readinto[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_readinto = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_readinto,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_readinto,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 49,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_readinto,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_readinto + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_readinto + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_writebit
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_writebit[23] = {
    0x2a, 0x0e,
    MP_QSTR_writebit & 0xff, MP_QSTR_writebit >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x23, 0x00,
    0x12, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x14, MP_QSTR_writebit & 0xff, MP_QSTR_writebit >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0xb1, 
    0x36, 0x02, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_writebit[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_value),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_writebit = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_writebit,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_writebit,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_writebit,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_writebit + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_writebit + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_writebyte
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_writebyte[23] = {
    0x2a, 0x0e,
    MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x26, 0x00,
    0x12, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x14, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0xb1, 
    0x36, 0x02, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_writebyte[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_value),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_writebyte = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_writebyte,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_writebyte,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_writebyte,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_writebyte + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_writebyte + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_write
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_write[35] = {
    0x52, 0x10,
    MP_QSTR_write & 0xff, MP_QSTR_write >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x29, 0x26, 0x00,
    0xb1, 
    0x5f, 
    0x4b, 0x12, 0x00, 
    0xc2, 
    0x12, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x14, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0xb0, 
    0x13, MP_QSTR_pin & 0xff, MP_QSTR_pin >> 8, 
    0xb2, 
    0x36, 0x02, 
    0x59, 
    0x42, 0xeb, 0x7f, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_write[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_buf),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_write = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_write,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_write,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_write,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_write + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_write + 10,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_select_rom
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_select_rom[38] = {
    0x22, 0x12,
    MP_QSTR_select_rom & 0xff, MP_QSTR_select_rom >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x2d, 0x27, 0x2a, 0x00,
    0xb0, 
    0x14, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8, 
    0x36, 0x00, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0x22, 0x80, 0x55, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0xb1, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_select_rom[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_rom),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_select_rom = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_select_rom,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_select_rom,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 38,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_select_rom,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_select_rom + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_select_rom + 11,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_scan
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_scan[77] = {
    0x49, 0x20,
    MP_QSTR_scan & 0xff, MP_QSTR_scan >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x32, 0x23, 0x24, 0x22, 0x26, 0x2c, 0x24, 0x26, 0x26, 0x2e, 0x00,
    0x2b, 0x00, 
    0xc1, 
    0x22, 0x80, 0x41, 
    0xc2, 
    0x50, 
    0xc3, 
    0x80, 
    0x42, 0x23, 0x80, 
    0x57, 
    0xc4, 
    0xb0, 
    0x14, MP_QSTR__search_rom & 0xff, MP_QSTR__search_rom >> 8, 
    0xb3, 
    0xb2, 
    0x36, 0x02, 
    0x30, 0x02, 
    0xc3, 
    0xc2, 
    0xb3, 
    0x44, 0x06, 0x80, 
    0xb1, 
    0xb3, 
    0x2b, 0x01, 
    0xe5, 
    0xc1, 
    0xb2, 
    0x80, 
    0xd9, 
    0x44, 0x03, 0x80, 
    0x42, 0x0a, 0x80, 
    0x81, 
    0xe5, 
    0x57, 
    0x22, 0x81, 0x7f, 
    0xd7, 
    0x43, 0xd5, 0x7f, 
    0x59, 
    0xb1, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_scan[1] = {
    MP_ROM_QSTR(MP_QSTR_self),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_scan = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_scan,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_scan,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 77,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_scan,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_scan + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_scan + 18,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire__search_rom
STATIC const byte fun_data_onewire__lt_module_gt__OneWire__search_rom[202] = {
    0x73, 0x3e,
    MP_QSTR__search_rom & 0xff, MP_QSTR__search_rom >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x3e, 0x29, 0x25, 0x2a, 0x24, 0x27, 0x27, 0x22, 0x24, 0x26, 0x22, 0x26, 0x27, 0x29, 0x24, 0x48, 0x24, 0x36, 0x22, 0x22, 0x28, 0x24, 0x26, 0x2d, 0x2d, 0x00,
    0xb0, 
    0x14, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8, 
    0x36, 0x00, 
    0x43, 0x05, 0x80, 
    0x51, 
    0x80, 
    0x2a, 0x02, 
    0x63, 
    0xb0, 
    0x14, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0x22, 0x81, 0x70, 
    0x36, 0x01, 
    0x59, 
    0xb1, 
    0x43, 0x07, 0x80, 
    0x12, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0x88, 
    0x34, 0x01, 
    0xc1, 
    0x12, MP_QSTR_bytearray & 0xff, MP_QSTR_bytearray >> 8, 
    0x88, 
    0x34, 0x01, 
    0xc3, 
    0x80, 
    0xc4, 
    0x22, 0x80, 0x40, 
    0xc5, 
    0x80, 
    0x42, 0x69, 0x80, 
    0x57, 
    0xc6, 
    0x80, 
    0xc7, 
    0x80, 
    0x42, 0x54, 0x80, 
    0x57, 
    0xc8, 
    0xb0, 
    0x14, MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8, 
    0x36, 0x00, 
    0xc9, 
    0xb0, 
    0x14, MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8, 
    0x36, 0x00, 
    0x44, 0x0c, 0x80, 
    0xb9, 
    0x44, 0x05, 0x80, 
    0x51, 
    0x80, 
    0x2a, 0x02, 
    0x63, 
    0x42, 0x1e, 0x80, 
    0xb9, 
    0x43, 0x1a, 0x80, 
    0xb2, 
    0xb5, 
    0xd8, 
    0x43, 0x10, 0x80, 
    0xb1, 
    0xb6, 
    0x55, 
    0x81, 
    0xb8, 
    0xf0, 
    0xef, 
    0x44, 0x0a, 0x80, 
    0xb2, 
    0xb5, 
    0xdc, 
    0x44, 0x04, 0x80, 
    0x81, 
    0xc9, 
    0xb5, 
    0xc4, 
    0xb0, 
    0x14, MP_QSTR_writebit & 0xff, MP_QSTR_writebit >> 8, 
    0xb9, 
    0x36, 0x01, 
    0x59, 
    0xb9, 
    0x44, 0x06, 0x80, 
    0xb7, 
    0x81, 
    0xb8, 
    0xf0, 
    0xe0, 
    0xc7, 
    0xb5, 
    0x81, 
    0xe6, 
    0xc5, 
    0x81, 
    0xe5, 
    0x57, 
    0x88, 
    0xd7, 
    0x43, 0xa6, 0x7f, 
    0x59, 
    0xb7, 
    0xb3, 
    0xb6, 
    0x56, 
    0x81, 
    0xe5, 
    0x57, 
    0x88, 
    0xd7, 
    0x43, 0x91, 0x7f, 
    0x59, 
    0xb3, 
    0xb4, 
    0x2a, 0x02, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire__search_rom[3] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_l_rom),
    MP_ROM_QSTR(MP_QSTR_diff),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire__search_rom = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 3,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire__search_rom,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire__search_rom,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 202,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 15,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__search_rom,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire__search_rom + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire__search_rom + 33,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire_crc8
STATIC const byte fun_data_onewire__lt_module_gt__OneWire_crc8[19] = {
    0x22, 0x0e,
    MP_QSTR_crc8 & 0xff, MP_QSTR_crc8 >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x80, 0x5a, 0x00,
    0x12, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x14, MP_QSTR_crc8 & 0xff, MP_QSTR_crc8 >> 8, 
    0xb1, 
    0x36, 0x01, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire_crc8[2] = {
    MP_ROM_QSTR(MP_QSTR_self),
    MP_ROM_QSTR(MP_QSTR_data),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire_crc8 = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire_crc8,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire_crc8,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 19,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_crc8,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire_crc8 + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire_crc8 + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire__lt_module_gt__OneWire
STATIC const byte fun_data_onewire__lt_module_gt__OneWire[126] = {
    0x08, 0x38,
    MP_QSTR_OneWire & 0xff, MP_QSTR_OneWire >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x8c, 0x0a, 0x26, 0x26, 0x46, 0x65, 0x20, 0x69, 0x60, 0x65, 0x65, 0x65, 0x20, 0x65, 0x65, 0x65, 0x20, 0x65, 0x40, 0x85, 0x0c, 0x85, 0x1c, 0x00,
    0x11, MP_QSTR___name__ & 0xff, MP_QSTR___name__ >> 8, 
    0x16, MP_QSTR___module__ & 0xff, MP_QSTR___module__ >> 8, 
    0x10, MP_QSTR_OneWire & 0xff, MP_QSTR_OneWire >> 8, 
    0x16, MP_QSTR___qualname__ & 0xff, MP_QSTR___qualname__ >> 8, 
    0x22, 0x81, 0x70, 
    0x16, MP_QSTR_SEARCH_ROM & 0xff, MP_QSTR_SEARCH_ROM >> 8, 
    0x22, 0x80, 0x55, 
    0x16, MP_QSTR_MATCH_ROM & 0xff, MP_QSTR_MATCH_ROM >> 8, 
    0x22, 0x81, 0x4c, 
    0x16, MP_QSTR_SKIP_ROM & 0xff, MP_QSTR_SKIP_ROM >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR___init__ & 0xff, MP_QSTR___init__ >> 8, 
    0x50, 
    0x2a, 0x01, 
    0x53, 
    0x33, 0x01, 
    0x16, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR_readbit & 0xff, MP_QSTR_readbit >> 8, 
    0x32, 0x03, 
    0x16, MP_QSTR_readbyte & 0xff, MP_QSTR_readbyte >> 8, 
    0x32, 0x04, 
    0x16, MP_QSTR_readinto & 0xff, MP_QSTR_readinto >> 8, 
    0x32, 0x05, 
    0x16, MP_QSTR_writebit & 0xff, MP_QSTR_writebit >> 8, 
    0x32, 0x06, 
    0x16, MP_QSTR_writebyte & 0xff, MP_QSTR_writebyte >> 8, 
    0x32, 0x07, 
    0x16, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0x32, 0x08, 
    0x16, MP_QSTR_select_rom & 0xff, MP_QSTR_select_rom >> 8, 
    0x32, 0x09, 
    0x16, MP_QSTR_scan & 0xff, MP_QSTR_scan >> 8, 
    0x32, 0x0a, 
    0x16, MP_QSTR__search_rom & 0xff, MP_QSTR__search_rom >> 8, 
    0x32, 0x0b, 
    0x16, MP_QSTR_crc8 & 0xff, MP_QSTR_crc8 >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt__OneWire[12] = {
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire___init__),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_reset),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_readbit),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_readbyte),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_readinto),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_writebit),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_writebyte),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_write),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_select_rom),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_scan),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire__search_rom),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire_crc8),
};
STATIC const mp_raw_code_t raw_code_onewire__lt_module_gt__OneWire = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_onewire__lt_module_gt__OneWire,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt__OneWire,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 126,
    .n_obj = 0,
    .n_raw_code = 12,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_OneWire,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt__OneWire + 0,
        .opcodes = fun_data_onewire__lt_module_gt__OneWire + 30,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file onewire.py, scope onewire_<module>
STATIC const byte fun_data_onewire__lt_module_gt_[62] = {
    0x18, 0x12,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_onewire_dot_py & 0xff, MP_QSTR_onewire_dot_py >> 8,
    0x60, 0x30, 0x48, 0x6e, 0x00,
    0x80, 
    0x10, MP_QSTR_const & 0xff, MP_QSTR_const >> 8, 
    0x2a, 0x01, 
    0x1b, MP_QSTR_micropython & 0xff, MP_QSTR_micropython >> 8, 
    0x1c, MP_QSTR_const & 0xff, MP_QSTR_const >> 8, 
    0x16, MP_QSTR_const & 0xff, MP_QSTR_const >> 8, 
    0x59, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR__onewire & 0xff, MP_QSTR__onewire >> 8, 
    0x16, MP_QSTR__ow & 0xff, MP_QSTR__ow >> 8, 
    0x54, 
    0x32, 0x00, 
    0x10, MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8, 
    0x11, MP_QSTR_Exception & 0xff, MP_QSTR_Exception >> 8, 
    0x34, 0x03, 
    0x16, MP_QSTR_OneWireError & 0xff, MP_QSTR_OneWireError >> 8, 
    0x54, 
    0x32, 0x01, 
    0x10, MP_QSTR_OneWire & 0xff, MP_QSTR_OneWire >> 8, 
    0x34, 0x02, 
    0x16, MP_QSTR_OneWire & 0xff, MP_QSTR_OneWire >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_onewire__lt_module_gt_[2] = {
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWireError),
    MP_ROM_PTR(&raw_code_onewire__lt_module_gt__OneWire),
};
const mp_raw_code_t raw_code_onewire__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_onewire__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_onewire__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 62,
    .n_obj = 0,
    .n_raw_code = 2,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_onewire_dot_py,
        .line_info = fun_data_onewire__lt_module_gt_ + 0,
        .opcodes = fun_data_onewire__lt_module_gt_ + 11,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl.py, scope webrepl__lt_module_gt__setup_conn
STATIC const byte fun_data_webrepl__lt_module_gt__setup_conn[180] = {
    0x6a, 0x28,
    MP_QSTR_setup_conn & 0xff, MP_QSTR_setup_conn >> 8,
    MP_QSTR_webrepl_dot_py & 0xff, MP_QSTR_webrepl_dot_py >> 8,
    0x80, 0x0c, 0x20, 0x2b, 0x56, 0x2d, 0x46, 0x2a, 0x2a, 0x24, 0x31, 0x33, 0x2a, 0x29, 0x37, 0x00,
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x14, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x36, 0x00, 
    0x17, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x12, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x14, MP_QSTR_setsockopt & 0xff, MP_QSTR_setsockopt >> 8, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x13, MP_QSTR_SOL_SOCKET & 0xff, MP_QSTR_SOL_SOCKET >> 8, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x13, MP_QSTR_SO_REUSEADDR & 0xff, MP_QSTR_SO_REUSEADDR >> 8, 
    0x81, 
    0x36, 0x03, 
    0x59, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x14, MP_QSTR_getaddrinfo & 0xff, MP_QSTR_getaddrinfo >> 8, 
    0x10, MP_QSTR_0_dot_0_dot_0_dot_0 & 0xff, MP_QSTR_0_dot_0_dot_0_dot_0 >> 8, 
    0xb0, 
    0x36, 0x02, 
    0xc2, 
    0xb2, 
    0x80, 
    0x55, 
    0x84, 
    0x55, 
    0xc3, 
    0x12, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x14, MP_QSTR_bind & 0xff, MP_QSTR_bind >> 8, 
    0xb3, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x14, MP_QSTR_listen & 0xff, MP_QSTR_listen >> 8, 
    0x81, 
    0x36, 0x01, 
    0x59, 
    0xb1, 
    0x44, 0x11, 0x80, 
    0x12, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x14, MP_QSTR_setsockopt & 0xff, MP_QSTR_setsockopt >> 8, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x13, MP_QSTR_SOL_SOCKET & 0xff, MP_QSTR_SOL_SOCKET >> 8, 
    0x94, 
    0xb1, 
    0x36, 0x03, 
    0x59, 
    0x12, MP_QSTR_network & 0xff, MP_QSTR_network >> 8, 
    0x13, MP_QSTR_AP_IF & 0xff, MP_QSTR_AP_IF >> 8, 
    0x12, MP_QSTR_network & 0xff, MP_QSTR_network >> 8, 
    0x13, MP_QSTR_STA_IF & 0xff, MP_QSTR_STA_IF >> 8, 
    0x2a, 0x02, 
    0x5f, 
    0x4b, 0x2b, 0x00, 
    0xc4, 
    0x12, MP_QSTR_network & 0xff, MP_QSTR_network >> 8, 
    0x14, MP_QSTR_WLAN & 0xff, MP_QSTR_WLAN >> 8, 
    0xb4, 
    0x36, 0x01, 
    0xc5, 
    0xb5, 
    0x14, MP_QSTR_active & 0xff, MP_QSTR_active >> 8, 
    0x36, 0x00, 
    0x44, 0x14, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x02, 
    0xb5, 
    0x14, MP_QSTR_ifconfig & 0xff, MP_QSTR_ifconfig >> 8, 
    0x36, 0x00, 
    0x80, 
    0x55, 
    0xb0, 
    0x2a, 0x02, 
    0xf8, 
    0x34, 0x01, 
    0x59, 
    0x42, 0xd2, 0x7f, 
    0x12, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_webrepl__lt_module_gt__setup_conn_0 = {{&mp_type_str}, 6721, 36, (const byte*)"\x57\x65\x62\x52\x45\x50\x4c\x20\x64\x61\x65\x6d\x6f\x6e\x20\x73\x74\x61\x72\x74\x65\x64\x20\x6f\x6e\x20\x77\x73\x3a\x2f\x2f\x25\x73\x3a\x25\x64"};
STATIC const mp_rom_obj_t const_table_data_webrepl__lt_module_gt__setup_conn[3] = {
    MP_ROM_QSTR(MP_QSTR_port),
    MP_ROM_QSTR(MP_QSTR_accept_handler),
    MP_ROM_PTR(&const_obj_webrepl__lt_module_gt__setup_conn_0),
};
STATIC const mp_raw_code_t raw_code_webrepl__lt_module_gt__setup_conn = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_webrepl__lt_module_gt__setup_conn,
    .const_table = (mp_uint_t*)const_table_data_webrepl__lt_module_gt__setup_conn,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 180,
    .n_obj = 1,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 14,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_setup_conn,
        .qstr_source_file = MP_QSTR_webrepl_dot_py,
        .line_info = fun_data_webrepl__lt_module_gt__setup_conn + 0,
        .opcodes = fun_data_webrepl__lt_module_gt__setup_conn + 22,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl.py, scope webrepl__lt_module_gt__accept_conn
STATIC const byte fun_data_webrepl__lt_module_gt__accept_conn[177] = {
    0x49, 0x2e,
    MP_QSTR_accept_conn & 0xff, MP_QSTR_accept_conn >> 8,
    MP_QSTR_webrepl_dot_py & 0xff, MP_QSTR_webrepl_dot_py >> 8,
    0x80, 0x1f, 0x20, 0x2a, 0x2a, 0x2a, 0x24, 0x2c, 0x27, 0x22, 0x29, 0x24, 0x2a, 0x2b, 0x2a, 0x48, 0x2d, 0x34, 0x00,
    0xb0, 
    0x14, MP_QSTR_accept & 0xff, MP_QSTR_accept >> 8, 
    0x36, 0x00, 
    0x30, 0x02, 
    0xc1, 
    0xc2, 
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x14, MP_QSTR_dupterm & 0xff, MP_QSTR_dupterm >> 8, 
    0x51, 
    0x36, 0x01, 
    0xc3, 
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x14, MP_QSTR_dupterm & 0xff, MP_QSTR_dupterm >> 8, 
    0xb3, 
    0x36, 0x01, 
    0x59, 
    0xb3, 
    0x44, 0x15, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x01, 
    0xb2, 
    0x10, MP_QSTR_rejected & 0xff, MP_QSTR_rejected >> 8, 
    0x34, 0x03, 
    0x59, 
    0xb1, 
    0x14, MP_QSTR_close & 0xff, MP_QSTR_close >> 8, 
    0x36, 0x00, 
    0x59, 
    0x51, 
    0x63, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x02, 
    0xb2, 
    0x34, 0x02, 
    0x59, 
    0xb1, 
    0x17, MP_QSTR_client_s & 0xff, MP_QSTR_client_s >> 8, 
    0x12, MP_QSTR_websocket_helper & 0xff, MP_QSTR_websocket_helper >> 8, 
    0x14, MP_QSTR_server_handshake & 0xff, MP_QSTR_server_handshake >> 8, 
    0xb1, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_uwebsocket & 0xff, MP_QSTR_uwebsocket >> 8, 
    0x14, MP_QSTR_websocket & 0xff, MP_QSTR_websocket >> 8, 
    0xb1, 
    0x52, 
    0x36, 0x02, 
    0xc4, 
    0x12, MP_QSTR__webrepl & 0xff, MP_QSTR__webrepl >> 8, 
    0x14, MP_QSTR__webrepl & 0xff, MP_QSTR__webrepl >> 8, 
    0xb4, 
    0x36, 0x01, 
    0xc4, 
    0xb1, 
    0x14, MP_QSTR_setblocking & 0xff, MP_QSTR_setblocking >> 8, 
    0x50, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_hasattr & 0xff, MP_QSTR_hasattr >> 8, 
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x23, 0x03, 
    0x34, 0x02, 
    0x44, 0x14, 0x80, 
    0xb1, 
    0x14, MP_QSTR_setsockopt & 0xff, MP_QSTR_setsockopt >> 8, 
    0x12, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x13, MP_QSTR_SOL_SOCKET & 0xff, MP_QSTR_SOL_SOCKET >> 8, 
    0x94, 
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x13, MP_QSTR_dupterm_notify & 0xff, MP_QSTR_dupterm_notify >> 8, 
    0x36, 0x03, 
    0x59, 
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x14, MP_QSTR_dupterm & 0xff, MP_QSTR_dupterm >> 8, 
    0xb4, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_webrepl__lt_module_gt__accept_conn_0 = {{&mp_type_str}, 16607, 35, (const byte*)"\x0a\x43\x6f\x6e\x63\x75\x72\x72\x65\x6e\x74\x20\x57\x65\x62\x52\x45\x50\x4c\x20\x63\x6f\x6e\x6e\x65\x63\x74\x69\x6f\x6e\x20\x66\x72\x6f\x6d"};
STATIC const mp_obj_str_t const_obj_webrepl__lt_module_gt__accept_conn_1 = {{&mp_type_str}, 13454, 25, (const byte*)"\x0a\x57\x65\x62\x52\x45\x50\x4c\x20\x63\x6f\x6e\x6e\x65\x63\x74\x69\x6f\x6e\x20\x66\x72\x6f\x6d\x3a"};
STATIC const mp_obj_str_t const_obj_webrepl__lt_module_gt__accept_conn_2 = {{&mp_type_str}, 30646, 14, (const byte*)"\x64\x75\x70\x74\x65\x72\x6d\x5f\x6e\x6f\x74\x69\x66\x79"};
STATIC const mp_rom_obj_t const_table_data_webrepl__lt_module_gt__accept_conn[4] = {
    MP_ROM_QSTR(MP_QSTR_listen_sock),
    MP_ROM_PTR(&const_obj_webrepl__lt_module_gt__accept_conn_0),
    MP_ROM_PTR(&const_obj_webrepl__lt_module_gt__accept_conn_1),
    MP_ROM_PTR(&const_obj_webrepl__lt_module_gt__accept_conn_2),
};
STATIC const mp_raw_code_t raw_code_webrepl__lt_module_gt__accept_conn = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_webrepl__lt_module_gt__accept_conn,
    .const_table = (mp_uint_t*)const_table_data_webrepl__lt_module_gt__accept_conn,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 177,
    .n_obj = 3,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_accept_conn,
        .qstr_source_file = MP_QSTR_webrepl_dot_py,
        .line_info = fun_data_webrepl__lt_module_gt__accept_conn + 0,
        .opcodes = fun_data_webrepl__lt_module_gt__accept_conn + 25,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl.py, scope webrepl__lt_module_gt__stop
STATIC const byte fun_data_webrepl__lt_module_gt__stop[56] = {
    0x10, 0x18,
    MP_QSTR_stop & 0xff, MP_QSTR_stop >> 8,
    MP_QSTR_webrepl_dot_py & 0xff, MP_QSTR_webrepl_dot_py >> 8,
    0x80, 0x34, 0x20, 0x2a, 0x26, 0x29, 0x26, 0x00,
    0x12, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x14, MP_QSTR_dupterm & 0xff, MP_QSTR_dupterm >> 8, 
    0x51, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_client_s & 0xff, MP_QSTR_client_s >> 8, 
    0x44, 0x09, 0x80, 
    0x12, MP_QSTR_client_s & 0xff, MP_QSTR_client_s >> 8, 
    0x14, MP_QSTR_close & 0xff, MP_QSTR_close >> 8, 
    0x36, 0x00, 
    0x59, 
    0x12, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x44, 0x09, 0x80, 
    0x12, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x14, MP_QSTR_close & 0xff, MP_QSTR_close >> 8, 
    0x36, 0x00, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_webrepl__lt_module_gt__stop = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_webrepl__lt_module_gt__stop,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 56,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_stop,
        .qstr_source_file = MP_QSTR_webrepl_dot_py,
        .line_info = fun_data_webrepl__lt_module_gt__stop + 0,
        .opcodes = fun_data_webrepl__lt_module_gt__stop + 14,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl.py, scope webrepl__lt_module_gt__start
STATIC const byte fun_data_webrepl__lt_module_gt__start[122] = {
    0xbe, 0x80, 0x01, 0x22,
    MP_QSTR_start & 0xff, MP_QSTR_start >> 8,
    MP_QSTR_webrepl_dot_py & 0xff, MP_QSTR_webrepl_dot_py >> 8,
    0x80, 0x3d, 0x26, 0x26, 0x23, 0x26, 0x2d, 0x2a, 0x4c, 0x4f, 0x2a, 0x2a, 0x00,
    0x12, MP_QSTR_stop & 0xff, MP_QSTR_stop >> 8, 
    0x34, 0x00, 
    0x59, 
    0xb1, 
    0x51, 
    0xde, 
    0x44, 0x3b, 0x80, 
    0x48, 0x28, 0x00, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_webrepl_cfg & 0xff, MP_QSTR_webrepl_cfg >> 8, 
    0xc2, 
    0x12, MP_QSTR__webrepl & 0xff, MP_QSTR__webrepl >> 8, 
    0x14, MP_QSTR_password & 0xff, MP_QSTR_password >> 8, 
    0xb2, 
    0x13, MP_QSTR_PASS & 0xff, MP_QSTR_PASS >> 8, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_setup_conn & 0xff, MP_QSTR_setup_conn >> 8, 
    0xb0, 
    0x12, MP_QSTR_accept_conn & 0xff, MP_QSTR_accept_conn >> 8, 
    0x34, 0x02, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x02, 
    0x34, 0x01, 
    0x59, 
    0x4a, 0x0d, 0x00, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x03, 
    0x34, 0x01, 
    0x59, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x42, 0x1c, 0x80, 
    0x12, MP_QSTR__webrepl & 0xff, MP_QSTR__webrepl >> 8, 
    0x14, MP_QSTR_password & 0xff, MP_QSTR_password >> 8, 
    0xb1, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_setup_conn & 0xff, MP_QSTR_setup_conn >> 8, 
    0xb0, 
    0x12, MP_QSTR_accept_conn & 0xff, MP_QSTR_accept_conn >> 8, 
    0x34, 0x02, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x04, 
    0x34, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_webrepl__lt_module_gt__start_0 = {{&mp_type_str}, 16616, 30, (const byte*)"\x53\x74\x61\x72\x74\x65\x64\x20\x77\x65\x62\x72\x65\x70\x6c\x20\x69\x6e\x20\x6e\x6f\x72\x6d\x61\x6c\x20\x6d\x6f\x64\x65"};
STATIC const mp_obj_str_t const_obj_webrepl__lt_module_gt__start_1 = {{&mp_type_str}, 39750, 53, (const byte*)"\x57\x65\x62\x52\x45\x50\x4c\x20\x69\x73\x20\x6e\x6f\x74\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x2c\x20\x72\x75\x6e\x20\x27\x69\x6d\x70\x6f\x72\x74\x20\x77\x65\x62\x72\x65\x70\x6c\x5f\x73\x65\x74\x75\x70\x27"};
STATIC const mp_obj_str_t const_obj_webrepl__lt_module_gt__start_2 = {{&mp_type_str}, 57813, 39, (const byte*)"\x53\x74\x61\x72\x74\x65\x64\x20\x77\x65\x62\x72\x65\x70\x6c\x20\x69\x6e\x20\x6d\x61\x6e\x75\x61\x6c\x20\x6f\x76\x65\x72\x72\x69\x64\x65\x20\x6d\x6f\x64\x65"};
STATIC const mp_rom_obj_t const_table_data_webrepl__lt_module_gt__start[5] = {
    MP_ROM_QSTR(MP_QSTR_port),
    MP_ROM_QSTR(MP_QSTR_password),
    MP_ROM_PTR(&const_obj_webrepl__lt_module_gt__start_0),
    MP_ROM_PTR(&const_obj_webrepl__lt_module_gt__start_1),
    MP_ROM_PTR(&const_obj_webrepl__lt_module_gt__start_2),
};
STATIC const mp_raw_code_t raw_code_webrepl__lt_module_gt__start = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_webrepl__lt_module_gt__start,
    .const_table = (mp_uint_t*)const_table_data_webrepl__lt_module_gt__start,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 122,
    .n_obj = 3,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name = MP_QSTR_start,
        .qstr_source_file = MP_QSTR_webrepl_dot_py,
        .line_info = fun_data_webrepl__lt_module_gt__start + 0,
        .opcodes = fun_data_webrepl__lt_module_gt__start + 21,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl.py, scope webrepl__lt_module_gt__start_foreground
STATIC const byte fun_data_webrepl__lt_module_gt__start_foreground[35] = {
    0xa1, 0x01, 0x12,
    MP_QSTR_start_foreground & 0xff, MP_QSTR_start_foreground >> 8,
    MP_QSTR_webrepl_dot_py & 0xff, MP_QSTR_webrepl_dot_py >> 8,
    0x80, 0x4d, 0x26, 0x28, 0x00,
    0x12, MP_QSTR_stop & 0xff, MP_QSTR_stop >> 8, 
    0x34, 0x00, 
    0x59, 
    0x12, MP_QSTR_setup_conn & 0xff, MP_QSTR_setup_conn >> 8, 
    0xb0, 
    0x51, 
    0x34, 0x02, 
    0xc1, 
    0x12, MP_QSTR_accept_conn & 0xff, MP_QSTR_accept_conn >> 8, 
    0xb1, 
    0x34, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_webrepl__lt_module_gt__start_foreground[1] = {
    MP_ROM_QSTR(MP_QSTR_port),
};
STATIC const mp_raw_code_t raw_code_webrepl__lt_module_gt__start_foreground = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_webrepl__lt_module_gt__start_foreground,
    .const_table = (mp_uint_t*)const_table_data_webrepl__lt_module_gt__start_foreground,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 35,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name = MP_QSTR_start_foreground,
        .qstr_source_file = MP_QSTR_webrepl_dot_py,
        .line_info = fun_data_webrepl__lt_module_gt__start_foreground + 0,
        .opcodes = fun_data_webrepl__lt_module_gt__start_foreground + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl.py, scope webrepl_<module>
STATIC const byte fun_data_webrepl__lt_module_gt_[122] = {
    0x08, 0x2c,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_webrepl_dot_py & 0xff, MP_QSTR_webrepl_dot_py >> 8,
    0x20, 0x28, 0x28, 0x28, 0x28, 0x28, 0x48, 0x24, 0x44, 0x85, 0x13, 0x85, 0x15, 0x85, 0x09, 0x8d, 0x10, 0x00,
    0x80, 
    0x51, 
    0x1b, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x16, MP_QSTR_socket & 0xff, MP_QSTR_socket >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x16, MP_QSTR_uos & 0xff, MP_QSTR_uos >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_network & 0xff, MP_QSTR_network >> 8, 
    0x16, MP_QSTR_network & 0xff, MP_QSTR_network >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uwebsocket & 0xff, MP_QSTR_uwebsocket >> 8, 
    0x16, MP_QSTR_uwebsocket & 0xff, MP_QSTR_uwebsocket >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_websocket_helper & 0xff, MP_QSTR_websocket_helper >> 8, 
    0x16, MP_QSTR_websocket_helper & 0xff, MP_QSTR_websocket_helper >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR__webrepl & 0xff, MP_QSTR__webrepl >> 8, 
    0x16, MP_QSTR__webrepl & 0xff, MP_QSTR__webrepl >> 8, 
    0x51, 
    0x17, MP_QSTR_listen_s & 0xff, MP_QSTR_listen_s >> 8, 
    0x51, 
    0x17, MP_QSTR_client_s & 0xff, MP_QSTR_client_s >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR_setup_conn & 0xff, MP_QSTR_setup_conn >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_accept_conn & 0xff, MP_QSTR_accept_conn >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR_stop & 0xff, MP_QSTR_stop >> 8, 
    0x22, 0x80, 0xc0, 0x4a, 
    0x51, 
    0x2a, 0x02, 
    0x53, 
    0x33, 0x03, 
    0x16, MP_QSTR_start & 0xff, MP_QSTR_start >> 8, 
    0x22, 0x80, 0xc0, 0x4a, 
    0x2a, 0x01, 
    0x53, 
    0x33, 0x04, 
    0x16, MP_QSTR_start_foreground & 0xff, MP_QSTR_start_foreground >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_webrepl__lt_module_gt_[5] = {
    MP_ROM_PTR(&raw_code_webrepl__lt_module_gt__setup_conn),
    MP_ROM_PTR(&raw_code_webrepl__lt_module_gt__accept_conn),
    MP_ROM_PTR(&raw_code_webrepl__lt_module_gt__stop),
    MP_ROM_PTR(&raw_code_webrepl__lt_module_gt__start),
    MP_ROM_PTR(&raw_code_webrepl__lt_module_gt__start_foreground),
};
const mp_raw_code_t raw_code_webrepl__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_webrepl__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_webrepl__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 122,
    .n_obj = 0,
    .n_raw_code = 5,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_webrepl_dot_py,
        .line_info = fun_data_webrepl__lt_module_gt_ + 0,
        .opcodes = fun_data_webrepl__lt_module_gt_ + 24,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl_setup.py, scope webrepl_setup__lt_module_gt__input_choice
STATIC const byte fun_data_webrepl_setup__lt_module_gt__input_choice[32] = {
    0x22, 0x14,
    MP_QSTR_input_choice & 0xff, MP_QSTR_input_choice >> 8,
    MP_QSTR_webrepl_setup_dot_py & 0xff, MP_QSTR_webrepl_setup_dot_py >> 8,
    0x80, 0x09, 0x20, 0x27, 0x26, 0x00,
    0x12, MP_QSTR_input & 0xff, MP_QSTR_input >> 8, 
    0xb0, 
    0x34, 0x01, 
    0xc2, 
    0xb2, 
    0xb1, 
    0xdd, 
    0x44, 0x02, 0x80, 
    0xb2, 
    0x63, 
    0x42, 0xee, 0x7f, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_webrepl_setup__lt_module_gt__input_choice[2] = {
    MP_ROM_QSTR(MP_QSTR_prompt),
    MP_ROM_QSTR(MP_QSTR_choices),
};
STATIC const mp_raw_code_t raw_code_webrepl_setup__lt_module_gt__input_choice = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 2,
    .fun_data = fun_data_webrepl_setup__lt_module_gt__input_choice,
    .const_table = (mp_uint_t*)const_table_data_webrepl_setup__lt_module_gt__input_choice,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 32,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_input_choice,
        .qstr_source_file = MP_QSTR_webrepl_setup_dot_py,
        .line_info = fun_data_webrepl_setup__lt_module_gt__input_choice + 0,
        .opcodes = fun_data_webrepl_setup__lt_module_gt__input_choice + 12,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl_setup.py, scope webrepl_setup__lt_module_gt__getpass
STATIC const byte fun_data_webrepl_setup__lt_module_gt__getpass[16] = {
    0x11, 0x0e,
    MP_QSTR_getpass & 0xff, MP_QSTR_getpass >> 8,
    MP_QSTR_webrepl_setup_dot_py & 0xff, MP_QSTR_webrepl_setup_dot_py >> 8,
    0x80, 0x0f, 0x00,
    0x12, MP_QSTR_input & 0xff, MP_QSTR_input >> 8, 
    0xb0, 
    0x34, 0x01, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_webrepl_setup__lt_module_gt__getpass[1] = {
    MP_ROM_QSTR(MP_QSTR_prompt),
};
STATIC const mp_raw_code_t raw_code_webrepl_setup__lt_module_gt__getpass = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_webrepl_setup__lt_module_gt__getpass,
    .const_table = (mp_uint_t*)const_table_data_webrepl_setup__lt_module_gt__getpass,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_getpass,
        .qstr_source_file = MP_QSTR_webrepl_setup_dot_py,
        .line_info = fun_data_webrepl_setup__lt_module_gt__getpass + 0,
        .opcodes = fun_data_webrepl_setup__lt_module_gt__getpass + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl_setup.py, scope webrepl_setup__lt_module_gt__input_pass
STATIC const byte fun_data_webrepl_setup__lt_module_gt__input_pass[87] = {
    0x18, 0x1e,
    MP_QSTR_input_pass & 0xff, MP_QSTR_input_pass >> 8,
    MP_QSTR_webrepl_setup_dot_py & 0xff, MP_QSTR_webrepl_setup_dot_py >> 8,
    0x80, 0x12, 0x20, 0x28, 0x36, 0x28, 0x23, 0x28, 0x26, 0x22, 0x00,
    0x12, MP_QSTR_getpass & 0xff, MP_QSTR_getpass >> 8, 
    0x23, 0x00, 
    0x34, 0x01, 
    0xc0, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0xb0, 
    0x34, 0x01, 
    0x84, 
    0xd7, 
    0x43, 0x0b, 0x80, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0xb0, 
    0x34, 0x01, 
    0x89, 
    0xd8, 
    0x44, 0x0b, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x01, 
    0x34, 0x01, 
    0x59, 
    0x42, 0x18, 0x80, 
    0x12, MP_QSTR_getpass & 0xff, MP_QSTR_getpass >> 8, 
    0x23, 0x02, 
    0x34, 0x01, 
    0xc1, 
    0xb0, 
    0xb1, 
    0xd9, 
    0x44, 0x02, 0x80, 
    0xb0, 
    0x63, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x03, 
    0x34, 0x01, 
    0x59, 
    0x42, 0xbc, 0x7f, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__input_pass_0 = {{&mp_type_str}, 12822, 26, (const byte*)"\x4e\x65\x77\x20\x70\x61\x73\x73\x77\x6f\x72\x64\x20\x28\x34\x2d\x39\x20\x63\x68\x61\x72\x73\x29\x3a\x20"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__input_pass_1 = {{&mp_type_str}, 22679, 23, (const byte*)"\x49\x6e\x76\x61\x6c\x69\x64\x20\x70\x61\x73\x73\x77\x6f\x72\x64\x20\x6c\x65\x6e\x67\x74\x68"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__input_pass_2 = {{&mp_type_str}, 25106, 18, (const byte*)"\x43\x6f\x6e\x66\x69\x72\x6d\x20\x70\x61\x73\x73\x77\x6f\x72\x64\x3a\x20"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__input_pass_3 = {{&mp_type_str}, 36388, 22, (const byte*)"\x50\x61\x73\x73\x77\x6f\x72\x64\x73\x20\x64\x6f\x20\x6e\x6f\x74\x20\x6d\x61\x74\x63\x68"};
STATIC const mp_rom_obj_t const_table_data_webrepl_setup__lt_module_gt__input_pass[4] = {
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__input_pass_0),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__input_pass_1),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__input_pass_2),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__input_pass_3),
};
STATIC const mp_raw_code_t raw_code_webrepl_setup__lt_module_gt__input_pass = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_webrepl_setup__lt_module_gt__input_pass,
    .const_table = (mp_uint_t*)const_table_data_webrepl_setup__lt_module_gt__input_pass,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 87,
    .n_obj = 4,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_input_pass,
        .qstr_source_file = MP_QSTR_webrepl_setup_dot_py,
        .line_info = fun_data_webrepl_setup__lt_module_gt__input_pass + 0,
        .opcodes = fun_data_webrepl_setup__lt_module_gt__input_pass + 17,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl_setup.py, scope webrepl_setup__lt_module_gt__exists
STATIC const byte fun_data_webrepl_setup__lt_module_gt__exists[52] = {
    0xb1, 0x02, 0x16,
    MP_QSTR_exists & 0xff, MP_QSTR_exists >> 8,
    MP_QSTR_webrepl_setup_dot_py & 0xff, MP_QSTR_webrepl_setup_dot_py >> 8,
    0x80, 0x1e, 0x23, 0x2a, 0x23, 0x4e, 0x00,
    0x48, 0x12, 0x00, 
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0xb0, 
    0x34, 0x01, 
    0x47, 0x02, 0x00, 
    0x59, 
    0x51, 
    0x5c, 
    0x5d, 
    0x52, 
    0x63, 
    0x4a, 0x0f, 0x00, 
    0x57, 
    0x12, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8, 
    0xdf, 
    0x44, 0x06, 0x80, 
    0x59, 
    0x50, 
    0x63, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_webrepl_setup__lt_module_gt__exists[1] = {
    MP_ROM_QSTR(MP_QSTR_fname),
};
STATIC const mp_raw_code_t raw_code_webrepl_setup__lt_module_gt__exists = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_webrepl_setup__lt_module_gt__exists,
    .const_table = (mp_uint_t*)const_table_data_webrepl_setup__lt_module_gt__exists,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 52,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_exists,
        .qstr_source_file = MP_QSTR_webrepl_setup_dot_py,
        .line_info = fun_data_webrepl_setup__lt_module_gt__exists + 0,
        .opcodes = fun_data_webrepl_setup__lt_module_gt__exists + 14,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl_setup.py, scope webrepl_setup__lt_module_gt__get_daemon_status
STATIC const byte fun_data_webrepl_setup__lt_module_gt__get_daemon_status[67] = {
    0x54, 0x1a,
    MP_QSTR_get_daemon_status & 0xff, MP_QSTR_get_daemon_status >> 8,
    MP_QSTR_webrepl_setup_dot_py & 0xff, MP_QSTR_webrepl_setup_dot_py >> 8,
    0x80, 0x27, 0x2c, 0x26, 0x28, 0x2c, 0x22, 0x25, 0x00,
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0x12, MP_QSTR_RC & 0xff, MP_QSTR_RC >> 8, 
    0x34, 0x01, 
    0x47, 0x25, 0x00, 
    0xc0, 
    0xb0, 
    0x5f, 
    0x4b, 0x1c, 0x00, 
    0xc1, 
    0x10, MP_QSTR_webrepl & 0xff, MP_QSTR_webrepl >> 8, 
    0xb1, 
    0xdd, 
    0x44, 0x10, 0x80, 
    0xb1, 
    0x14, MP_QSTR_startswith & 0xff, MP_QSTR_startswith >> 8, 
    0x10, MP_QSTR__hash_ & 0xff, MP_QSTR__hash_ >> 8, 
    0x36, 0x01, 
    0x44, 0x02, 0x80, 
    0x50, 
    0x63, 
    0x52, 
    0x63, 
    0x42, 0xe1, 0x7f, 
    0x51, 
    0x63, 
    0x51, 
    0x5c, 
    0x5d, 
    0x51, 
    0x63, 
};
STATIC const mp_raw_code_t raw_code_webrepl_setup__lt_module_gt__get_daemon_status = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_webrepl_setup__lt_module_gt__get_daemon_status,
    .const_table = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 67,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_get_daemon_status,
        .qstr_source_file = MP_QSTR_webrepl_setup_dot_py,
        .line_info = fun_data_webrepl_setup__lt_module_gt__get_daemon_status + 0,
        .opcodes = fun_data_webrepl_setup__lt_module_gt__get_daemon_status + 15,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl_setup.py, scope webrepl_setup__lt_module_gt__change_daemon
STATIC const byte fun_data_webrepl_setup__lt_module_gt__change_daemon[202] = {
    0xa9, 0x12, 0x2c,
    MP_QSTR_change_daemon & 0xff, MP_QSTR_change_daemon >> 8,
    MP_QSTR_webrepl_setup_dot_py & 0xff, MP_QSTR_webrepl_setup_dot_py >> 8,
    0x80, 0x31, 0x27, 0x3f, 0x22, 0x26, 0x26, 0x26, 0x22, 0x30, 0x2e, 0x2c, 0x2c, 0x2b, 0x24, 0x6f, 0x2c, 0x00,
    0x23, 0x01, 
    0x23, 0x02, 
    0x2a, 0x02, 
    0xc1, 
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0x12, MP_QSTR_RC & 0xff, MP_QSTR_RC >> 8, 
    0x34, 0x01, 
    0x47, 0x7c, 0x00, 
    0xc2, 
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0x12, MP_QSTR_RC & 0xff, MP_QSTR_RC >> 8, 
    0x10, MP_QSTR__dot_tmp & 0xff, MP_QSTR__dot_tmp >> 8, 
    0xf2, 
    0x10, MP_QSTR_w & 0xff, MP_QSTR_w >> 8, 
    0x34, 0x02, 
    0x47, 0x66, 0x00, 
    0xc3, 
    0x50, 
    0xc4, 
    0xb2, 
    0x5f, 
    0x4b, 0x50, 0x00, 
    0xc5, 
    0xb1, 
    0x5f, 
    0x4b, 0x3f, 0x00, 
    0xc6, 
    0xb6, 
    0xb5, 
    0xdd, 
    0x44, 0x35, 0x80, 
    0x52, 
    0xc4, 
    0xb0, 
    0x44, 0x16, 0x80, 
    0xb5, 
    0x14, MP_QSTR_startswith & 0xff, MP_QSTR_startswith >> 8, 
    0x10, MP_QSTR__hash_ & 0xff, MP_QSTR__hash_ >> 8, 
    0x36, 0x01, 
    0x44, 0x0a, 0x80, 
    0xb5, 
    0x81, 
    0x51, 
    0x2e, 0x02, 
    0x55, 
    0xc5, 
    0x42, 0x19, 0x80, 
    0xb0, 
    0x43, 0x15, 0x80, 
    0xb5, 
    0x14, MP_QSTR_startswith & 0xff, MP_QSTR_startswith >> 8, 
    0x10, MP_QSTR__hash_ & 0xff, MP_QSTR__hash_ >> 8, 
    0x36, 0x01, 
    0x43, 0x09, 0x80, 
    0x10, MP_QSTR__hash_ & 0xff, MP_QSTR__hash_ >> 8, 
    0xb5, 
    0xf2, 
    0xc5, 
    0x42, 0x00, 0x80, 
    0x42, 0xbe, 0x7f, 
    0xb3, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0xb5, 
    0x36, 0x01, 
    0x59, 
    0x42, 0xad, 0x7f, 
    0xb4, 
    0x43, 0x09, 0x80, 
    0xb3, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0x23, 0x03, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x5c, 
    0x5d, 
    0x51, 
    0x5c, 
    0x5d, 
    0x12, MP_QSTR_os & 0xff, MP_QSTR_os >> 8, 
    0x14, MP_QSTR_remove & 0xff, MP_QSTR_remove >> 8, 
    0x12, MP_QSTR_RC & 0xff, MP_QSTR_RC >> 8, 
    0x36, 0x01, 
    0x59, 
    0x12, MP_QSTR_os & 0xff, MP_QSTR_os >> 8, 
    0x14, MP_QSTR_rename & 0xff, MP_QSTR_rename >> 8, 
    0x12, MP_QSTR_RC & 0xff, MP_QSTR_RC >> 8, 
    0x10, MP_QSTR__dot_tmp & 0xff, MP_QSTR__dot_tmp >> 8, 
    0xf2, 
    0x12, MP_QSTR_RC & 0xff, MP_QSTR_RC >> 8, 
    0x36, 0x02, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__change_daemon_0 = {{&mp_type_str}, 42115, 14, (const byte*)"\x69\x6d\x70\x6f\x72\x74\x20\x77\x65\x62\x72\x65\x70\x6c"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__change_daemon_1 = {{&mp_type_str}, 30641, 15, (const byte*)"\x77\x65\x62\x72\x65\x70\x6c\x2e\x73\x74\x61\x72\x74\x28\x29"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__change_daemon_2 = {{&mp_type_str}, 34423, 31, (const byte*)"\x69\x6d\x70\x6f\x72\x74\x20\x77\x65\x62\x72\x65\x70\x6c\x0a\x77\x65\x62\x72\x65\x70\x6c\x2e\x73\x74\x61\x72\x74\x28\x29\x0a"};
STATIC const mp_rom_obj_t const_table_data_webrepl_setup__lt_module_gt__change_daemon[4] = {
    MP_ROM_QSTR(MP_QSTR_action),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__change_daemon_0),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__change_daemon_1),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__change_daemon_2),
};
STATIC const mp_raw_code_t raw_code_webrepl_setup__lt_module_gt__change_daemon = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_webrepl_setup__lt_module_gt__change_daemon,
    .const_table = (mp_uint_t*)const_table_data_webrepl_setup__lt_module_gt__change_daemon,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 202,
    .n_obj = 3,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 22,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_change_daemon,
        .qstr_source_file = MP_QSTR_webrepl_setup_dot_py,
        .line_info = fun_data_webrepl_setup__lt_module_gt__change_daemon + 0,
        .opcodes = fun_data_webrepl_setup__lt_module_gt__change_daemon + 25,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl_setup.py, scope webrepl_setup__lt_module_gt__main
STATIC const byte fun_data_webrepl_setup__lt_module_gt__main[297] = {
    0x54, 0x3a,
    MP_QSTR_main & 0xff, MP_QSTR_main >> 8,
    MP_QSTR_webrepl_setup_dot_py & 0xff, MP_QSTR_webrepl_setup_dot_py >> 8,
    0x80, 0x46, 0x46, 0x35, 0x28, 0x28, 0x4e, 0x28, 0x2b, 0x56, 0x28, 0x44, 0x28, 0x26, 0x2f, 0x6f, 0x1f, 0x27, 0x28, 0x49, 0x4b, 0x28, 0x33, 0x28, 0x00,
    0x12, MP_QSTR_get_daemon_status & 0xff, MP_QSTR_get_daemon_status >> 8, 
    0x34, 0x00, 
    0xc0, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x00, 
    0xb0, 
    0x44, 0x06, 0x80, 
    0x10, MP_QSTR_enabled & 0xff, MP_QSTR_enabled >> 8, 
    0x42, 0x03, 0x80, 
    0x10, MP_QSTR_disabled & 0xff, MP_QSTR_disabled >> 8, 
    0x34, 0x02, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x01, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x02, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_input & 0xff, MP_QSTR_input >> 8, 
    0x10, MP_QSTR__gt__space_ & 0xff, MP_QSTR__gt__space_ >> 8, 
    0x34, 0x01, 
    0x14, MP_QSTR_upper & 0xff, MP_QSTR_upper >> 8, 
    0x36, 0x00, 
    0xc1, 
    0xb1, 
    0x10, MP_QSTR_E & 0xff, MP_QSTR_E >> 8, 
    0xd9, 
    0x44, 0x59, 0x80, 
    0x12, MP_QSTR_exists & 0xff, MP_QSTR_exists >> 8, 
    0x12, MP_QSTR_CONFIG & 0xff, MP_QSTR_CONFIG >> 8, 
    0x34, 0x01, 
    0x44, 0x16, 0x80, 
    0x12, MP_QSTR_input_choice & 0xff, MP_QSTR_input_choice >> 8, 
    0x23, 0x03, 
    0x10, MP_QSTR_y & 0xff, MP_QSTR_y >> 8, 
    0x10, MP_QSTR_n & 0xff, MP_QSTR_n >> 8, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0x2a, 0x03, 
    0x34, 0x02, 
    0xc2, 
    0x42, 0x0c, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x04, 
    0x34, 0x01, 
    0x59, 
    0x10, MP_QSTR_y & 0xff, MP_QSTR_y >> 8, 
    0xc2, 
    0xb2, 
    0x10, MP_QSTR_y & 0xff, MP_QSTR_y >> 8, 
    0xd9, 
    0x44, 0x24, 0x80, 
    0x12, MP_QSTR_input_pass & 0xff, MP_QSTR_input_pass >> 8, 
    0x34, 0x00, 
    0xc3, 
    0x12, MP_QSTR_open & 0xff, MP_QSTR_open >> 8, 
    0x12, MP_QSTR_CONFIG & 0xff, MP_QSTR_CONFIG >> 8, 
    0x10, MP_QSTR_w & 0xff, MP_QSTR_w >> 8, 
    0x34, 0x02, 
    0x47, 0x0e, 0x00, 
    0xc4, 
    0xb4, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0x10, MP_QSTR_PASS_space__equals__space__percent_r_0x0a_ & 0xff, MP_QSTR_PASS_space__equals__space__percent_r_0x0a_ >> 8, 
    0xb3, 
    0xf8, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x5c, 
    0x5d, 
    0xb1, 
    0x10, MP_QSTR_D & 0xff, MP_QSTR_D >> 8, 
    0x10, MP_QSTR_E & 0xff, MP_QSTR_E >> 8, 
    0x2a, 0x02, 
    0xdd, 
    0xd3, 
    0x43, 0x18, 0x80, 
    0xb1, 
    0x10, MP_QSTR_D & 0xff, MP_QSTR_D >> 8, 
    0xd9, 
    0x44, 0x04, 0x80, 
    0xb0, 
    0x44, 0x0c, 0x80, 
    0xb1, 
    0x10, MP_QSTR_E & 0xff, MP_QSTR_E >> 8, 
    0xd9, 
    0x44, 0x15, 0x80, 
    0xb0, 
    0x44, 0x11, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x05, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x14, MP_QSTR_exit & 0xff, MP_QSTR_exit >> 8, 
    0x36, 0x00, 
    0x59, 
    0x12, MP_QSTR_change_daemon & 0xff, MP_QSTR_change_daemon >> 8, 
    0xb1, 
    0x10, MP_QSTR_E & 0xff, MP_QSTR_E >> 8, 
    0xd9, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x06, 
    0x34, 0x01, 
    0x59, 
    0x12, MP_QSTR_input_choice & 0xff, MP_QSTR_input_choice >> 8, 
    0x23, 0x07, 
    0x10, MP_QSTR_y & 0xff, MP_QSTR_y >> 8, 
    0x10, MP_QSTR_n & 0xff, MP_QSTR_n >> 8, 
    0x10, MP_QSTR_ & 0xff, MP_QSTR_ >> 8, 
    0x2a, 0x03, 
    0x34, 0x02, 
    0xc1, 
    0xb1, 
    0x10, MP_QSTR_y & 0xff, MP_QSTR_y >> 8, 
    0xd9, 
    0x44, 0x09, 0x80, 
    0x12, MP_QSTR_machine & 0xff, MP_QSTR_machine >> 8, 
    0x14, MP_QSTR_reset & 0xff, MP_QSTR_reset >> 8, 
    0x36, 0x00, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__main_0 = {{&mp_type_str}, 24126, 33, (const byte*)"\x57\x65\x62\x52\x45\x50\x4c\x20\x64\x61\x65\x6d\x6f\x6e\x20\x61\x75\x74\x6f\x2d\x73\x74\x61\x72\x74\x20\x73\x74\x61\x74\x75\x73\x3a"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__main_1 = {{&mp_type_str}, 9123, 60, (const byte*)"\x0a\x57\x6f\x75\x6c\x64\x20\x79\x6f\x75\x20\x6c\x69\x6b\x65\x20\x74\x6f\x20\x28\x45\x29\x6e\x61\x62\x6c\x65\x20\x6f\x72\x20\x28\x44\x29\x69\x73\x61\x62\x6c\x65\x20\x69\x74\x20\x72\x75\x6e\x6e\x69\x6e\x67\x20\x6f\x6e\x20\x62\x6f\x6f\x74\x3f"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__main_2 = {{&mp_type_str}, 39613, 20, (const byte*)"\x28\x45\x6d\x70\x74\x79\x20\x6c\x69\x6e\x65\x20\x74\x6f\x20\x71\x75\x69\x74\x29"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__main_3 = {{&mp_type_str}, 49111, 49, (const byte*)"\x57\x6f\x75\x6c\x64\x20\x79\x6f\x75\x20\x6c\x69\x6b\x65\x20\x74\x6f\x20\x63\x68\x61\x6e\x67\x65\x20\x57\x65\x62\x52\x45\x50\x4c\x20\x70\x61\x73\x73\x77\x6f\x72\x64\x3f\x20\x28\x79\x2f\x6e\x29\x20"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__main_4 = {{&mp_type_str}, 7023, 47, (const byte*)"\x54\x6f\x20\x65\x6e\x61\x62\x6c\x65\x20\x57\x65\x62\x52\x45\x50\x4c\x2c\x20\x79\x6f\x75\x20\x6d\x75\x73\x74\x20\x73\x65\x74\x20\x70\x61\x73\x73\x77\x6f\x72\x64\x20\x66\x6f\x72\x20\x69\x74"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__main_5 = {{&mp_type_str}, 24025, 26, (const byte*)"\x4e\x6f\x20\x66\x75\x72\x74\x68\x65\x72\x20\x61\x63\x74\x69\x6f\x6e\x20\x72\x65\x71\x75\x69\x72\x65\x64"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__main_6 = {{&mp_type_str}, 15057, 38, (const byte*)"\x43\x68\x61\x6e\x67\x65\x73\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x61\x63\x74\x69\x76\x61\x74\x65\x64\x20\x61\x66\x74\x65\x72\x20\x72\x65\x62\x6f\x6f\x74"};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__main_7 = {{&mp_type_str}, 7554, 36, (const byte*)"\x57\x6f\x75\x6c\x64\x20\x79\x6f\x75\x20\x6c\x69\x6b\x65\x20\x74\x6f\x20\x72\x65\x62\x6f\x6f\x74\x20\x6e\x6f\x77\x3f\x20\x28\x79\x2f\x6e\x29\x20"};
STATIC const mp_rom_obj_t const_table_data_webrepl_setup__lt_module_gt__main[8] = {
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__main_0),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__main_1),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__main_2),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__main_3),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__main_4),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__main_5),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__main_6),
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__main_7),
};
STATIC const mp_raw_code_t raw_code_webrepl_setup__lt_module_gt__main = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_webrepl_setup__lt_module_gt__main,
    .const_table = (mp_uint_t*)const_table_data_webrepl_setup__lt_module_gt__main,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 297,
    .n_obj = 8,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_main,
        .qstr_source_file = MP_QSTR_webrepl_setup_dot_py,
        .line_info = fun_data_webrepl_setup__lt_module_gt__main + 0,
        .opcodes = fun_data_webrepl_setup__lt_module_gt__main + 31,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file webrepl_setup.py, scope webrepl_setup_<module>
STATIC const byte fun_data_webrepl_setup__lt_module_gt_[103] = {
    0x08, 0x2e,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_webrepl_setup_dot_py & 0xff, MP_QSTR_webrepl_setup_dot_py >> 8,
    0x48, 0x28, 0x48, 0x26, 0x45, 0x65, 0x60, 0x65, 0x85, 0x0c, 0x85, 0x09, 0x85, 0x0a, 0x85, 0x15, 0x85, 0x20, 0x00,
    0x80, 
    0x51, 
    0x1b, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x16, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_os & 0xff, MP_QSTR_os >> 8, 
    0x16, MP_QSTR_os & 0xff, MP_QSTR_os >> 8, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_machine & 0xff, MP_QSTR_machine >> 8, 
    0x16, MP_QSTR_machine & 0xff, MP_QSTR_machine >> 8, 
    0x10, MP_QSTR__dot__slash_boot_dot_py & 0xff, MP_QSTR__dot__slash_boot_dot_py >> 8, 
    0x16, MP_QSTR_RC & 0xff, MP_QSTR_RC >> 8, 
    0x23, 0x00, 
    0x16, MP_QSTR_CONFIG & 0xff, MP_QSTR_CONFIG >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_input_choice & 0xff, MP_QSTR_input_choice >> 8, 
    0x32, 0x02, 
    0x16, MP_QSTR_getpass & 0xff, MP_QSTR_getpass >> 8, 
    0x32, 0x03, 
    0x16, MP_QSTR_input_pass & 0xff, MP_QSTR_input_pass >> 8, 
    0x32, 0x04, 
    0x16, MP_QSTR_exists & 0xff, MP_QSTR_exists >> 8, 
    0x32, 0x05, 
    0x16, MP_QSTR_get_daemon_status & 0xff, MP_QSTR_get_daemon_status >> 8, 
    0x32, 0x06, 
    0x16, MP_QSTR_change_daemon & 0xff, MP_QSTR_change_daemon >> 8, 
    0x32, 0x07, 
    0x16, MP_QSTR_main & 0xff, MP_QSTR_main >> 8, 
    0x11, MP_QSTR_main & 0xff, MP_QSTR_main >> 8, 
    0x34, 0x00, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_webrepl_setup__lt_module_gt__0 = {{&mp_type_str}, 32613, 16, (const byte*)"\x2e\x2f\x77\x65\x62\x72\x65\x70\x6c\x5f\x63\x66\x67\x2e\x70\x79"};
STATIC const mp_rom_obj_t const_table_data_webrepl_setup__lt_module_gt_[8] = {
    MP_ROM_PTR(&const_obj_webrepl_setup__lt_module_gt__0),
    MP_ROM_PTR(&raw_code_webrepl_setup__lt_module_gt__input_choice),
    MP_ROM_PTR(&raw_code_webrepl_setup__lt_module_gt__getpass),
    MP_ROM_PTR(&raw_code_webrepl_setup__lt_module_gt__input_pass),
    MP_ROM_PTR(&raw_code_webrepl_setup__lt_module_gt__exists),
    MP_ROM_PTR(&raw_code_webrepl_setup__lt_module_gt__get_daemon_status),
    MP_ROM_PTR(&raw_code_webrepl_setup__lt_module_gt__change_daemon),
    MP_ROM_PTR(&raw_code_webrepl_setup__lt_module_gt__main),
};
const mp_raw_code_t raw_code_webrepl_setup__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_webrepl_setup__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_webrepl_setup__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 103,
    .n_obj = 1,
    .n_raw_code = 7,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_webrepl_setup_dot_py,
        .line_info = fun_data_webrepl_setup__lt_module_gt_ + 0,
        .opcodes = fun_data_webrepl_setup__lt_module_gt_ + 25,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file websocket_helper.py, scope websocket_helper__lt_module_gt__server_handshake_<listcomp>
STATIC const byte fun_data_websocket_helper__lt_module_gt__server_handshake__lt_listcomp_gt_[29] = {
    0x41, 0x0e,
    MP_QSTR__lt_listcomp_gt_ & 0xff, MP_QSTR__lt_listcomp_gt_ >> 8,
    MP_QSTR_websocket_helper_dot_py & 0xff, MP_QSTR_websocket_helper_dot_py >> 8,
    0x80, 0x1a, 0x00,
    0x2b, 0x00, 
    0xb0, 
    0x5f, 
    0x4b, 0x0c, 0x00, 
    0xc1, 
    0xb1, 
    0x14, MP_QSTR_strip & 0xff, MP_QSTR_strip >> 8, 
    0x36, 0x00, 
    0x2f, 0x14, 
    0x42, 0xf1, 0x7f, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_websocket_helper__lt_module_gt__server_handshake__lt_listcomp_gt_[1] = {
    MP_ROM_QSTR(MP_QSTR__star_),
};
STATIC const mp_raw_code_t raw_code_websocket_helper__lt_module_gt__server_handshake__lt_listcomp_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_websocket_helper__lt_module_gt__server_handshake__lt_listcomp_gt_,
    .const_table = (mp_uint_t*)const_table_data_websocket_helper__lt_module_gt__server_handshake__lt_listcomp_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 29,
    .n_obj = 0,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_listcomp_gt_,
        .qstr_source_file = MP_QSTR_websocket_helper_dot_py,
        .line_info = fun_data_websocket_helper__lt_module_gt__server_handshake__lt_listcomp_gt_ + 0,
        .opcodes = fun_data_websocket_helper__lt_module_gt__server_handshake__lt_listcomp_gt_ + 9,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file websocket_helper.py, scope websocket_helper__lt_module_gt__server_handshake
STATIC const byte fun_data_websocket_helper__lt_module_gt__server_handshake[249] = {
    0x61, 0x44,
    MP_QSTR_server_handshake & 0xff, MP_QSTR_server_handshake >> 8,
    MP_QSTR_websocket_helper_dot_py & 0xff, MP_QSTR_websocket_helper_dot_py >> 8,
    0x80, 0x0d, 0x2b, 0x67, 0x42, 0x20, 0x27, 0x24, 0x28, 0x27, 0x43, 0x31, 0x26, 0x2a, 0x27, 0x45, 0x24, 0x48, 0x26, 0x4f, 0x2a, 0x29, 0x27, 0x2f, 0x26, 0x4a, 0x69, 0x40, 0x28, 0x00,
    0xb0, 
    0x14, MP_QSTR_makefile & 0xff, MP_QSTR_makefile >> 8, 
    0x10, MP_QSTR_rwb & 0xff, MP_QSTR_rwb >> 8, 
    0x80, 
    0x36, 0x02, 
    0xc1, 
    0xb1, 
    0x14, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8, 
    0x36, 0x00, 
    0xc2, 
    0x51, 
    0xc3, 
    0xb1, 
    0x14, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8, 
    0x36, 0x00, 
    0xc2, 
    0xb2, 
    0x43, 0x08, 0x80, 
    0x12, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8, 
    0x23, 0x01, 
    0x34, 0x01, 
    0x65, 
    0xb2, 
    0x23, 0x02, 
    0xd9, 
    0x44, 0x03, 0x80, 
    0x42, 0x2d, 0x80, 
    0x32, 0x09, 
    0xb2, 
    0x14, MP_QSTR_split & 0xff, MP_QSTR_split >> 8, 
    0x23, 0x03, 
    0x81, 
    0x36, 0x02, 
    0x34, 0x01, 
    0x30, 0x02, 
    0xc4, 
    0xc5, 
    0x12, MP_QSTR_DEBUG & 0xff, MP_QSTR_DEBUG >> 8, 
    0x44, 0x0a, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0xb4, 
    0xb5, 
    0x2a, 0x02, 
    0x34, 0x01, 
    0x59, 
    0xb4, 
    0x23, 0x04, 
    0xd9, 
    0x44, 0x02, 0x80, 
    0xb5, 
    0xc3, 
    0x42, 0xb6, 0x7f, 
    0xb3, 
    0x43, 0x08, 0x80, 
    0x12, MP_QSTR_OSError & 0xff, MP_QSTR_OSError >> 8, 
    0x23, 0x05, 
    0x34, 0x01, 
    0x65, 
    0x12, MP_QSTR_DEBUG & 0xff, MP_QSTR_DEBUG >> 8, 
    0x44, 0x0f, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x23, 0x06, 
    0xb3, 
    0x12, MP_QSTR_len & 0xff, MP_QSTR_len >> 8, 
    0xb3, 
    0x34, 0x01, 
    0x34, 0x03, 
    0x59, 
    0x12, MP_QSTR_hashlib & 0xff, MP_QSTR_hashlib >> 8, 
    0x14, MP_QSTR_sha1 & 0xff, MP_QSTR_sha1 >> 8, 
    0xb3, 
    0x36, 0x01, 
    0xc6, 
    0xb6, 
    0x14, MP_QSTR_update & 0xff, MP_QSTR_update >> 8, 
    0x23, 0x07, 
    0x36, 0x01, 
    0x59, 
    0xb6, 
    0x14, MP_QSTR_digest & 0xff, MP_QSTR_digest >> 8, 
    0x36, 0x00, 
    0xc7, 
    0x12, MP_QSTR_binascii & 0xff, MP_QSTR_binascii >> 8, 
    0x14, MP_QSTR_b2a_base64 & 0xff, MP_QSTR_b2a_base64 >> 8, 
    0xb7, 
    0x36, 0x01, 
    0x51, 
    0x7f, 
    0x2e, 0x02, 
    0x55, 
    0xc7, 
    0x12, MP_QSTR_DEBUG & 0xff, MP_QSTR_DEBUG >> 8, 
    0x44, 0x0a, 0x80, 
    0x12, MP_QSTR_print & 0xff, MP_QSTR_print >> 8, 
    0x10, MP_QSTR_respkey_colon_ & 0xff, MP_QSTR_respkey_colon_ >> 8, 
    0xb7, 
    0x34, 0x02, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_send & 0xff, MP_QSTR_send >> 8, 
    0x23, 0x08, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_send & 0xff, MP_QSTR_send >> 8, 
    0xb7, 
    0x36, 0x01, 
    0x59, 
    0xb0, 
    0x14, MP_QSTR_send & 0xff, MP_QSTR_send >> 8, 
    0x10, MP_QSTR__0x0d__0x0a__0x0d__0x0a_ & 0xff, MP_QSTR__0x0d__0x0a__0x0d__0x0a_ >> 8, 
    0x36, 0x01, 
    0x59, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__server_handshake_0 = {{&mp_type_str}, 54338, 14, (const byte*)"\x45\x4f\x46\x20\x69\x6e\x20\x68\x65\x61\x64\x65\x72\x73"};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__server_handshake_1 = {{&mp_type_bytes}, 27298, 2, (const byte*)"\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__server_handshake_2 = {{&mp_type_bytes}, 46495, 1, (const byte*)"\x3a"};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__server_handshake_3 = {{&mp_type_bytes}, 24914, 17, (const byte*)"\x53\x65\x63\x2d\x57\x65\x62\x53\x6f\x63\x6b\x65\x74\x2d\x4b\x65\x79"};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__server_handshake_4 = {{&mp_type_str}, 60085, 23, (const byte*)"\x4e\x6f\x74\x20\x61\x20\x77\x65\x62\x73\x6f\x63\x6b\x65\x74\x20\x72\x65\x71\x75\x65\x73\x74"};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__server_handshake_5 = {{&mp_type_str}, 35752, 18, (const byte*)"\x53\x65\x63\x2d\x57\x65\x62\x53\x6f\x63\x6b\x65\x74\x2d\x4b\x65\x79\x3a"};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__server_handshake_6 = {{&mp_type_bytes}, 43888, 36, (const byte*)"\x32\x35\x38\x45\x41\x46\x41\x35\x2d\x45\x39\x31\x34\x2d\x34\x37\x44\x41\x2d\x39\x35\x43\x41\x2d\x43\x35\x41\x42\x30\x44\x43\x38\x35\x42\x31\x31"};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__server_handshake_7 = {{&mp_type_bytes}, 65413, 97, (const byte*)"\x48\x54\x54\x50\x2f\x31\x2e\x31\x20\x31\x30\x31\x20\x53\x77\x69\x74\x63\x68\x69\x6e\x67\x20\x50\x72\x6f\x74\x6f\x63\x6f\x6c\x73\x0d\x0a\x55\x70\x67\x72\x61\x64\x65\x3a\x20\x77\x65\x62\x73\x6f\x63\x6b\x65\x74\x0d\x0a\x43\x6f\x6e\x6e\x65\x63\x74\x69\x6f\x6e\x3a\x20\x55\x70\x67\x72\x61\x64\x65\x0d\x0a\x53\x65\x63\x2d\x57\x65\x62\x53\x6f\x63\x6b\x65\x74\x2d\x41\x63\x63\x65\x70\x74\x3a\x20"};
STATIC const mp_rom_obj_t const_table_data_websocket_helper__lt_module_gt__server_handshake[10] = {
    MP_ROM_QSTR(MP_QSTR_sock),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__server_handshake_0),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__server_handshake_1),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__server_handshake_2),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__server_handshake_3),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__server_handshake_4),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__server_handshake_5),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__server_handshake_6),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__server_handshake_7),
    MP_ROM_PTR(&raw_code_websocket_helper__lt_module_gt__server_handshake__lt_listcomp_gt_),
};
STATIC const mp_raw_code_t raw_code_websocket_helper__lt_module_gt__server_handshake = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_websocket_helper__lt_module_gt__server_handshake,
    .const_table = (mp_uint_t*)const_table_data_websocket_helper__lt_module_gt__server_handshake,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 249,
    .n_obj = 8,
    .n_raw_code = 1,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_server_handshake,
        .qstr_source_file = MP_QSTR_websocket_helper_dot_py,
        .line_info = fun_data_websocket_helper__lt_module_gt__server_handshake + 0,
        .opcodes = fun_data_websocket_helper__lt_module_gt__server_handshake + 36,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file websocket_helper.py, scope websocket_helper__lt_module_gt__client_handshake
STATIC const byte fun_data_websocket_helper__lt_module_gt__client_handshake[65] = {
    0x31, 0x1c,
    MP_QSTR_client_handshake & 0xff, MP_QSTR_client_handshake >> 8,
    MP_QSTR_websocket_helper_dot_py & 0xff, MP_QSTR_websocket_helper_dot_py >> 8,
    0x80, 0x3a, 0x2b, 0x89, 0x08, 0x47, 0x20, 0x27, 0x27, 0x00,
    0xb0, 
    0x14, MP_QSTR_makefile & 0xff, MP_QSTR_makefile >> 8, 
    0x10, MP_QSTR_rwb & 0xff, MP_QSTR_rwb >> 8, 
    0x80, 
    0x36, 0x02, 
    0xc1, 
    0xb1, 
    0x14, MP_QSTR_write & 0xff, MP_QSTR_write >> 8, 
    0x23, 0x01, 
    0x36, 0x01, 
    0x59, 
    0xb1, 
    0x14, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8, 
    0x36, 0x00, 
    0xc2, 
    0xb1, 
    0x14, MP_QSTR_readline & 0xff, MP_QSTR_readline >> 8, 
    0x36, 0x00, 
    0xc2, 
    0xb2, 
    0x23, 0x02, 
    0xd9, 
    0x44, 0x03, 0x80, 
    0x42, 0x03, 0x80, 
    0x42, 0xec, 0x7f, 
    0x51, 
    0x63, 
};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__client_handshake_0 = {{&mp_type_bytes}, 52281, 109, (const byte*)"\x47\x45\x54\x20\x2f\x20\x48\x54\x54\x50\x2f\x31\x2e\x31\x0d\x0a\x48\x6f\x73\x74\x3a\x20\x65\x63\x68\x6f\x2e\x77\x65\x62\x73\x6f\x63\x6b\x65\x74\x2e\x6f\x72\x67\x0d\x0a\x43\x6f\x6e\x6e\x65\x63\x74\x69\x6f\x6e\x3a\x20\x55\x70\x67\x72\x61\x64\x65\x0d\x0a\x55\x70\x67\x72\x61\x64\x65\x3a\x20\x77\x65\x62\x73\x6f\x63\x6b\x65\x74\x0d\x0a\x53\x65\x63\x2d\x57\x65\x62\x53\x6f\x63\x6b\x65\x74\x2d\x4b\x65\x79\x3a\x20\x66\x6f\x6f\x0d\x0a\x0d\x0a"};
STATIC const mp_obj_str_t const_obj_websocket_helper__lt_module_gt__client_handshake_1 = {{&mp_type_bytes}, 27298, 2, (const byte*)"\x0d\x0a"};
STATIC const mp_rom_obj_t const_table_data_websocket_helper__lt_module_gt__client_handshake[3] = {
    MP_ROM_QSTR(MP_QSTR_sock),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__client_handshake_0),
    MP_ROM_PTR(&const_obj_websocket_helper__lt_module_gt__client_handshake_1),
};
STATIC const mp_raw_code_t raw_code_websocket_helper__lt_module_gt__client_handshake = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 1,
    .fun_data = fun_data_websocket_helper__lt_module_gt__client_handshake,
    .const_table = (mp_uint_t*)const_table_data_websocket_helper__lt_module_gt__client_handshake,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 65,
    .n_obj = 2,
    .n_raw_code = 0,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR_client_handshake,
        .qstr_source_file = MP_QSTR_websocket_helper_dot_py,
        .line_info = fun_data_websocket_helper__lt_module_gt__client_handshake + 0,
        .opcodes = fun_data_websocket_helper__lt_module_gt__client_handshake + 16,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

// frozen bytecode for file websocket_helper.py, scope websocket_helper_<module>
STATIC const byte fun_data_websocket_helper__lt_module_gt_[95] = {
    0x24, 0x1e,
    MP_QSTR__lt_module_gt_ & 0xff, MP_QSTR__lt_module_gt_ >> 8,
    MP_QSTR_websocket_helper_dot_py & 0xff, MP_QSTR_websocket_helper_dot_py >> 8,
    0x28, 0x23, 0x4c, 0x2c, 0x23, 0x4c, 0x4c, 0x44, 0x85, 0x2d, 0x00,
    0x80, 
    0x51, 
    0x1b, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x16, MP_QSTR_sys & 0xff, MP_QSTR_sys >> 8, 
    0x48, 0x0b, 0x00, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_ubinascii & 0xff, MP_QSTR_ubinascii >> 8, 
    0x16, MP_QSTR_binascii & 0xff, MP_QSTR_binascii >> 8, 
    0x4a, 0x0d, 0x00, 
    0x59, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_binascii & 0xff, MP_QSTR_binascii >> 8, 
    0x16, MP_QSTR_binascii & 0xff, MP_QSTR_binascii >> 8, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x48, 0x0b, 0x00, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_uhashlib & 0xff, MP_QSTR_uhashlib >> 8, 
    0x16, MP_QSTR_hashlib & 0xff, MP_QSTR_hashlib >> 8, 
    0x4a, 0x0d, 0x00, 
    0x59, 
    0x80, 
    0x51, 
    0x1b, MP_QSTR_hashlib & 0xff, MP_QSTR_hashlib >> 8, 
    0x16, MP_QSTR_hashlib & 0xff, MP_QSTR_hashlib >> 8, 
    0x4a, 0x01, 0x00, 
    0x5d, 
    0x80, 
    0x16, MP_QSTR_DEBUG & 0xff, MP_QSTR_DEBUG >> 8, 
    0x32, 0x00, 
    0x16, MP_QSTR_server_handshake & 0xff, MP_QSTR_server_handshake >> 8, 
    0x32, 0x01, 
    0x16, MP_QSTR_client_handshake & 0xff, MP_QSTR_client_handshake >> 8, 
    0x51, 
    0x63, 
};
STATIC const mp_rom_obj_t const_table_data_websocket_helper__lt_module_gt_[2] = {
    MP_ROM_PTR(&raw_code_websocket_helper__lt_module_gt__server_handshake),
    MP_ROM_PTR(&raw_code_websocket_helper__lt_module_gt__client_handshake),
};
const mp_raw_code_t raw_code_websocket_helper__lt_module_gt_ = {
    .kind = MP_CODE_BYTECODE,
    .scope_flags = 0x00,
    .n_pos_args = 0,
    .fun_data = fun_data_websocket_helper__lt_module_gt_,
    .const_table = (mp_uint_t*)const_table_data_websocket_helper__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 95,
    .n_obj = 0,
    .n_raw_code = 2,
    #if MICROPY_PY_SYS_SETTRACE
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name = MP_QSTR__lt_module_gt_,
        .qstr_source_file = MP_QSTR_websocket_helper_dot_py,
        .line_info = fun_data_websocket_helper__lt_module_gt_ + 0,
        .opcodes = fun_data_websocket_helper__lt_module_gt_ + 17,
    },
    .line_of_definition = 0,
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    .n_qstr = 0,
    .qstr_link = NULL,
    #endif
    #endif
    #if MICROPY_EMIT_MACHINE_CODE
    .type_sig = 0,
    #endif
};

const char mp_frozen_mpy_names[] = {
"flashbdev.py\0"
"inisetup.py\0"
"_boot.py\0"
"apa106.py\0"
"neopixel.py\0"
"upip.py\0"
"upip_utarfile.py\0"
"ntptime.py\0"
"dht.py\0"
"ds18x20.py\0"
"onewire.py\0"
"webrepl.py\0"
"webrepl_setup.py\0"
"websocket_helper.py\0"
"\0"};
const mp_raw_code_t *const mp_frozen_mpy_content[] = {
    &raw_code_flashbdev__lt_module_gt_,
    &raw_code_inisetup__lt_module_gt_,
    &raw_code__boot__lt_module_gt_,
    &raw_code_apa106__lt_module_gt_,
    &raw_code_neopixel__lt_module_gt_,
    &raw_code_upip__lt_module_gt_,
    &raw_code_upip_utarfile__lt_module_gt_,
    &raw_code_ntptime__lt_module_gt_,
    &raw_code_dht__lt_module_gt_,
    &raw_code_ds18x20__lt_module_gt_,
    &raw_code_onewire__lt_module_gt_,
    &raw_code_webrepl__lt_module_gt_,
    &raw_code_webrepl_setup__lt_module_gt_,
    &raw_code_websocket_helper__lt_module_gt_,
};
