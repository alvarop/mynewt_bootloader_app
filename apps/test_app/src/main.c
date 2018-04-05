#include <stdio.h>
#include "bsp/bsp.h"
#include "console/console.h"
#include "log/log.h"
#include "os/os.h"
#include "shell/shell.h"
#include "sysinit/sysinit.h"

struct log app_log;

static int shell_reset_cmd(int argc, char **argv) {
  NVIC_SystemReset();

  return 0;
}

static int shell_bootloader_cmd(int argc, char **argv) {
  console_printf("Attempting to enter bootloader\n");

  return 0;
}

static const char *test_module = "test";
static const struct shell_cmd test_module_commands[] = {
    {
        .sc_cmd = "reset",
        .sc_cmd_func = shell_reset_cmd,
    },
    {
        .sc_cmd = "bootloader",
        .sc_cmd_func = shell_bootloader_cmd,
    },
    {NULL, NULL, NULL},
};

int main(int argc, char **argv) {
  sysinit();

  log_register("log", &app_log, &log_console_handler, NULL, LOG_SYSLEVEL);

  shell_register(test_module, test_module_commands);
  shell_register_default_module(test_module);

  while (1) {
    os_eventq_run(os_eventq_dflt_get());
  }
}
