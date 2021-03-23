#include <stdio.h>
#include <string.h>

#include <X11/XKBlib.h>

const size_t LAYOUT_MAX_LEN = 32;

int layout_name(char *out) {
    Display *dpy = XOpenDisplay(NULL);
    if (dpy == NULL) {
        return -1;
    }

    int res = -1;
    XkbStateRec state;
    XkbGetState(dpy, XkbUseCoreKbd, &state);

    XkbDescPtr desc = XkbGetKeyboard(dpy, XkbAllComponentsMask, XkbUseCoreKbd);
    if (desc) {
        char *group = XGetAtomName(dpy, desc->names->groups[state.group]);

        if (group) {
            strncpy(out, group, LAYOUT_MAX_LEN);
            out[LAYOUT_MAX_LEN - 1] = '\0';

            XFree(group);
            res = 0;
        }

        XkbFreeKeyboard(desc, XkbAllComponentsMask, 1);
    }

    XCloseDisplay(dpy);

    return res;
}

int main(int argc, char** argv) {
    char layout[LAYOUT_MAX_LEN];
    if (layout_name(layout)) {
        return 1;
    }

    printf("%s", layout);
    return 0;
}
