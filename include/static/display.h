#ifndef CRUX_STATIC_DISPLAY_H
#define CRUX_STATIC_DISPLAY_H

#include "kernel_types.h"
#include "display_api.h"

#ifdef __cplusplus
extern "C" {
#endif

// The static rendering of the display contract: plain externs, defined by the
// display driver and linked into the binary. A static consumer pays zero
// indirection and cannot accidentally dispatch.
extern int32_t Display_GetDisplayCount(void);
extern bool Display_GetDisplayBounds(int32_t display, CruxRect *bounds);
extern void *Display_CreateWindow(const CruxWindowParams *params);
extern void Display_DestroyWindow(void *window);
extern void Display_SetWindowTitle(void *window, const char *title);
extern void Display_SetWindowPosition(void *window, int32_t x, int32_t y);
extern void Display_SetWindowSize(void *window, int32_t w, int32_t h);
extern void Display_SetWindowMinSize(void *window, int32_t minW, int32_t minH);
extern void Display_GetWindowSizeInPixels(void *window, int32_t *w, int32_t *h);
extern void Display_ShowWindow(void *window);
extern void Display_HideWindow(void *window);
extern void Display_RaiseWindow(void *window);
extern void Display_MinimizeWindow(void *window);
extern void Display_MaximizeWindow(void *window);
extern void Display_RestoreWindow(void *window);
extern void Display_SetWindowFullscreen(void *window, bool fullscreen);
extern bool Display_CreateWindowFramebuffer(void *window, uint32_t *format, void **pixels, int32_t *pitch);
extern void Display_DestroyWindowFramebuffer(void *window);
extern bool Display_UpdateWindowFramebuffer(void *window, const CruxRect *rects, int32_t count);

#ifdef __cplusplus
}
#endif

#endif
