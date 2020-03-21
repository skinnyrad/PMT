// Include required definitions first.
#include "py/obj.h"
#include "py/runtime.h"
#include "py/builtin.h"

//used in esp-idf rtc_wdt.c
#include "soc/rtc_wdt.h"
#include "soc/rtc.h"

//*******
// For reference on esp-idf v3.3:  grep -r rtc_wdt.c  on esp-idf directory


// This is the function which will be called from Python as example.add_ints(a, b).
STATIC mp_obj_t start(mp_obj_t pyobj_milliseconds) {
    // Extract the ints from the micropython input objects
    int millis = mp_obj_get_int(pyobj_milliseconds);

    /*
    //code copied from panic.c
    if (REG_GET_BIT(RTC_CNTL_WDTCONFIG0_REG, RTC_CNTL_WDT_EN)) {
        return mp_obj_new_int(1);
    }
    WRITE_PERI_REG(RTC_CNTL_WDTWPROTECT_REG, RTC_CNTL_WDT_WKEY_VALUE);
    WRITE_PERI_REG(RTC_CNTL_WDTFEED_REG, 1);
    REG_SET_FIELD(RTC_CNTL_WDTCONFIG0_REG, RTC_CNTL_WDT_SYS_RESET_LENGTH, 7);
    REG_SET_FIELD(RTC_CNTL_WDTCONFIG0_REG, RTC_CNTL_WDT_CPU_RESET_LENGTH, 7);
    REG_SET_FIELD(RTC_CNTL_WDTCONFIG0_REG, RTC_CNTL_WDT_STG0, RTC_WDT_STG_SEL_RESET_SYSTEM);
    // 64KB of core dump data (stacks of about 30 tasks) will produce ~85KB base64 data.
    // @ 115200 UART speed it will take more than 6 sec to print them out.
    WRITE_PERI_REG(RTC_CNTL_WDTCONFIG1_REG, rtc_clk_slow_freq_get_hz() * 7);
    REG_SET_BIT(RTC_CNTL_WDTCONFIG0_REG, RTC_CNTL_WDT_EN);
    WRITE_PERI_REG(RTC_CNTL_WDTWPROTECT_REG, 0);
    */

    rtc_wdt_protect_off();
    int err = rtc_wdt_set_time( 0, millis );
    rtc_wdt_set_length_of_reset_signal(0,7); //Sys reset len 7
    rtc_wdt_set_stage( 0, 4); //make stage 0 perform Sys reset + RTC reset
    rtc_wdt_enable();
    rtc_wdt_protect_on();

    // return possible error as MicroPython object.
    // Remeber err==0 is ESP_ERR_OK
    if(err){
        printf("rt_wdt Error: %d\n",err);
        return mp_obj_new_int(0);
    }

    return mp_obj_new_int(1);
    
}
// Define a Python reference to the function above
STATIC MP_DEFINE_CONST_FUN_OBJ_1(rtc_watchdog_start_obj, start);



// This is the function which will be called from Python as example.add_ints(a, b).
STATIC mp_obj_t stop() {

    /*
    //code copied directly from panic.c
    WRITE_PERI_REG(RTC_CNTL_WDTWPROTECT_REG, RTC_CNTL_WDT_WKEY_VALUE);
    WRITE_PERI_REG(RTC_CNTL_WDTFEED_REG, 1);
    REG_SET_FIELD(RTC_CNTL_WDTCONFIG0_REG, RTC_CNTL_WDT_STG0, RTC_WDT_STG_SEL_OFF);
    REG_CLR_BIT(RTC_CNTL_WDTCONFIG0_REG, RTC_CNTL_WDT_EN);
    WRITE_PERI_REG(RTC_CNTL_WDTWPROTECT_REG, 0);
    */

    rtc_wdt_disable();

    // return true as MicroPython object.
    return mp_obj_new_int(1);
}
// Define a Python reference to the function above
STATIC MP_DEFINE_CONST_FUN_OBJ_0(rtc_watchdog_stop_obj, stop);



// This is the function which will be called from Python as example.add_ints(a, b).
STATIC mp_obj_t feed() {
    
    /*
    //code extrapolated from start function
    WRITE_PERI_REG(RTC_CNTL_WDTWPROTECT_REG, RTC_CNTL_WDT_WKEY_VALUE);
    WRITE_PERI_REG(RTC_CNTL_WDTFEED_REG, 1);
    WRITE_PERI_REG(RTC_CNTL_WDTWPROTECT_REG, 0);
    */

    rtc_wdt_feed();

    // return true as MicroPython object.
    return mp_obj_new_int(1);
}
// Define a Python reference to the function above
STATIC MP_DEFINE_CONST_FUN_OBJ_0(rtc_watchdog_feed_obj, feed);


// Define all properties of the example module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t example_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_rtcwatchdog) },
    { MP_ROM_QSTR(MP_QSTR_start), MP_ROM_PTR(&rtc_watchdog_start_obj) },
    { MP_ROM_QSTR(MP_QSTR_stop), MP_ROM_PTR(&rtc_watchdog_stop_obj) },
    { MP_ROM_QSTR(MP_QSTR_feed), MP_ROM_PTR(&rtc_watchdog_feed_obj) },
};
STATIC MP_DEFINE_CONST_DICT(rtcwatchdog_module_globals, example_module_globals_table);

// Define module object.
const mp_obj_module_t rtcwatchdog_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&rtcwatchdog_module_globals,
};

// Register the module to make it available in Python
MP_REGISTER_MODULE(MP_QSTR_rtcwatchdog, rtcwatchdog_user_cmodule, MODULE_EXAMPLE_ENABLED);

