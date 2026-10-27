#ifndef CRUX_DYNAMIC_DISPLAY_H
#define CRUX_DYNAMIC_DISPLAY_H

#include "kernel_types.h"
#include "display_api.h"
#include "engine.h"
#include "kernel_types.h"

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The dynamic rendering of the display contract: every call dispatches through
// the engine's registry channel - the display driver's served DisplayAPI,
// selected by the concern's stable dispatch id (DRIVER_DISPLAY,
// platform_types.h).
#define DISPLAY_API ((DisplayAPI *)crux_engine_api->GetExtensionAPI(DRIVER_DISPLAY))
static inline int32_t Display_GetDisplayCount(void) { return DISPLAY_API->GetDisplayCount(); }
static inline bool Display_GetDisplayBounds(int32_t display, CruxRect *bounds) { return DISPLAY_API->GetDisplayBounds(display, bounds); }
static inline void *Display_CreateWindow(const CruxWindowParams *params) { return DISPLAY_API->CreateWindow(params); }
static inline void Display_DestroyWindow(void *window) { DISPLAY_API->DestroyWindow(window); }
static inline void Display_SetWindowTitle(void *window, const char *title) { DISPLAY_API->SetWindowTitle(window, title); }
static inline void Display_SetWindowPosition(void *window, int32_t x, int32_t y) { DISPLAY_API->SetWindowPosition(window, x, y); }
static inline void Display_SetWindowSize(void *window, int32_t w, int32_t h) { DISPLAY_API->SetWindowSize(window, w, h); }
static inline void Display_SetWindowMinSize(void *window, int32_t minW, int32_t minH) { DISPLAY_API->SetWindowMinSize(window, minW, minH); }
static inline void Display_GetWindowSizeInPixels(void *window, int32_t *w, int32_t *h) { DISPLAY_API->GetWindowSizeInPixels(window, w, h); }
static inline void Display_ShowWindow(void *window) { DISPLAY_API->ShowWindow(window); }
static inline void Display_HideWindow(void *window) { DISPLAY_API->HideWindow(window); }
static inline void Display_RaiseWindow(void *window) { DISPLAY_API->RaiseWindow(window); }
static inline void Display_MinimizeWindow(void *window) { DISPLAY_API->MinimizeWindow(window); }
static inline void Display_MaximizeWindow(void *window) { DISPLAY_API->MaximizeWindow(window); }
static inline void Display_RestoreWindow(void *window) { DISPLAY_API->RestoreWindow(window); }
static inline void Display_SetWindowFullscreen(void *window, bool fullscreen) { DISPLAY_API->SetWindowFullscreen(window, fullscreen); }
static inline bool Display_CreateWindowFramebuffer(void *window, uint32_t *format, void **pixels, int32_t *pitch) { return DISPLAY_API->CreateWindowFramebuffer(window, format, pixels, pitch); }
static inline void Display_DestroyWindowFramebuffer(void *window) { DISPLAY_API->DestroyWindowFramebuffer(window); }
static inline bool Display_UpdateWindowFramebuffer(void *window, const CruxRect *rects, int32_t count) { return DISPLAY_API->UpdateWindowFramebuffer(window, rects, count); }
#undef DISPLAY_API

#ifdef __cplusplus
}
#endif

#endif
