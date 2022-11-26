#include "lazylog.h"
#include <stdio.h>

static void send(char const *string, void *arg)
{
    fputs(string, arg);
    fflush(arg);
}

static char const *extreme_2047;
static char const *extreme_2048;
static char const extreme_2049[];

int main(void)
{
    zlog_setup(ZLOG_DEBUG, &send, stdout);
    zlog_debug("%s %d", "string", 932);
    zlog_info("%s %d", "string", 932);
    zlog_warn("%s %d", "string", 932);
    zlog_error("%s %d", "string", 932);
    zlog_fatal("%s %d", "string", 932);

    zlog_warn("%s%d", extreme_2047, 1);
    zlog_warn("%s%d", extreme_2048, 1);
    zlog_warn("%s%d", extreme_2049, 1);

    zlog_print(ZLOG_WARN, "fn", "/home/to/root/src/file.c", __LINE__, "oi");

    zlog_setroot("root");
    zlog_print(ZLOG_WARN, "fn", "/home/to/root/src/file.c", __LINE__, "oi");

    zlog_setroot("rot");
    zlog_print(ZLOG_WARN, "fn", "/home/to/root/src/file.c", __LINE__, "oi");
    return 0;
}

static char const extreme_2049[] =
    "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo "
    "ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis "
    "dis parturient montes, nascetur ridiculus mus. Donec quam felis, "
    "ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa "
    "quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, "
    "arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. "
    "Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras "
    "dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. "
    "Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. "
    "Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. "
    "Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean "
    "imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper "
    "ultricies nisi. Nam eget dui. Lorem ipsum dolor sit amet, consectetuer "
    "adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum "
    "sociis natoque penatibus et magnis dis parturient montes, nascetur "
    "ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium "
    "quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla "
    "vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, "
    "imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis "
    "pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. "
    "Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, "
    "consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, "
    "viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius "
    "laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel "
    "augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Lorem ipsum "
    "dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget "
    "dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis "
    "parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies "
    "nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. "
    "Donec pede justo,";

static char const *extreme_2047 = extreme_2049 + 2;
static char const *extreme_2048 = extreme_2049 + 1;
