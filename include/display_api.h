#ifndef CRUX_DISPLAY_API_H
#define CRUX_DISPLAY_API_H

#include "kernel_types.h"

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The display concern's contract: the one struct of function pointers the
// display driver fills and serves - the window + framebuffer surface.
// Handles are opaque per-platform records; the framebuffer format is an
// opaque tag (kernel_types.h); the framebuffer is driver-owned.
//
// The concern is dispatched through the engine's registry channel: the
// driver's served DisplayAPI, selected by the concern's stable dispatch id.
typedef struct DisplayAPI {
  PackageVersion version;
  int32_t (*GetDisplayCount)(void);
  bool (*GetDisplayBounds)(int32_t display, CruxRect *bounds);
  void *(*CreateWindow)(const CruxWindowParams *params);
  void (*DestroyWindow)(void *window);
  void (*SetWindowTitle)(void *window, const char *title);
  void (*SetWindowPosition)(void *window, int32_t x, int32_t y);
  void (*SetWindowSize)(void *window, int32_t w, int32_t h);
  void (*SetWindowMinSize)(void *window, int32_t minW, int32_t minH);
  void (*GetWindowSizeInPixels)(void *window, int32_t *w, int32_t *h);
  void (*ShowWindow)(void *window);
  void (*HideWindow)(void *window);
  void (*RaiseWindow)(void *window);
  void (*MinimizeWindow)(void *window);
  void (*MaximizeWindow)(void *window);
  void (*RestoreWindow)(void *window);
  void (*SetWindowFullscreen)(void *window, bool fullscreen);
  bool (*CreateWindowFramebuffer)(void *window, uint32_t *format, void **pixels, int32_t *pitch);
  void (*DestroyWindowFramebuffer)(void *window);
  bool (*UpdateWindowFramebuffer)(void *window, const CruxRect *rects, int32_t count);
} DisplayAPI;

#ifdef __cplusplus
}
#endif

#endif
