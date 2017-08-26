#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include <memory>
#include <tuple>

namespace sdl2xx {

  using audio_device_event      = SDL_AudioDeviceEvent;
  using controller_axis_event   = SDL_ControllerAxisEvent;
  using controller_button_event = SDL_ControllerButtonEvent;
  using controller_device_event = SDL_ControllerDeviceEvent;
  using dollar_gesture_event    = SDL_DollarGestureEvent;
  using drop_event              = SDL_DropEvent;
  using event                   = SDL_Event;
  using finger                  = SDL_Finger;
  using joy_axis_event          = SDL_JoyAxisEvent;
  using joy_ball_event          = SDL_JoyBallEvent;
  using joy_button_event        = SDL_JoyButtonEvent;
  using joy_device_event        = SDL_JoyDeviceEvent;
  using joy_hat_event           = SDL_JoyHatEvent;
  using keyboard_event          = SDL_KeyboardEvent;
  using mouse_button_event      = SDL_MouseButtonEvent;
  using mouse_motion_event      = SDL_MouseMotionEvent;
  using mouse_wheel_event       = SDL_MouseWheelEvent;
  using multi_gesture_event     = SDL_MultiGestureEvent;
  using quit_event              = SDL_QuitEvent;
  using syswm_event             = SDL_SysWMEvent;
  using text_editing_event      = SDL_TextEditingEvent;
  using text_input_event        = SDL_TextInputEvent;
  using touch_finger_event      = SDL_TouchFingerEvent;
  using user_event              = SDL_UserEvent;
  using window_event            = SDL_WindowEvent;

  using point = SDL_Point;
  using rect  = SDL_Rect;
  using color = SDL_Color;

  //////

  namespace events {
    enum : uint32_t {
      firstevent               = SDL_FIRSTEVENT,
      quit                     = SDL_QUIT,
      app_terminating          = SDL_APP_TERMINATING,
      app_lowmemory            = SDL_APP_LOWMEMORY,
      app_willenterbackground  = SDL_APP_WILLENTERBACKGROUND,
      app_didenterbackground   = SDL_APP_DIDENTERBACKGROUND,
      app_willenterforeground  = SDL_APP_WILLENTERFOREGROUND,
      app_didenterforeground   = SDL_APP_DIDENTERFOREGROUND,
      windowevent              = SDL_WINDOWEVENT,
      syswmevent               = SDL_SYSWMEVENT,
      keydown                  = SDL_KEYDOWN,
      keyup                    = SDL_KEYUP,
      textediting              = SDL_TEXTEDITING,
      textinput                = SDL_TEXTINPUT,
      keymapchanged            = SDL_KEYMAPCHANGED,
      mousemotion              = SDL_MOUSEMOTION,
      mousebuttondown          = SDL_MOUSEBUTTONDOWN,
      mousebuttonup            = SDL_MOUSEBUTTONUP,
      mousewheel               = SDL_MOUSEWHEEL,
      joyaxismotion            = SDL_JOYAXISMOTION,
      joyballmotion            = SDL_JOYBALLMOTION,
      joyhatmotion             = SDL_JOYHATMOTION,
      joybuttondown            = SDL_JOYBUTTONDOWN,
      joybuttonup              = SDL_JOYBUTTONUP,
      joydeviceadded           = SDL_JOYDEVICEADDED,
      joydeviceremoved         = SDL_JOYDEVICEREMOVED,
      controlleraxismotion     = SDL_CONTROLLERAXISMOTION,
      controllerbuttondown     = SDL_CONTROLLERBUTTONDOWN,
      controllerbuttonup       = SDL_CONTROLLERBUTTONUP,
      controllerdeviceadded    = SDL_CONTROLLERDEVICEADDED,
      controllerdeviceremoved  = SDL_CONTROLLERDEVICEREMOVED,
      controllerdeviceremapped = SDL_CONTROLLERDEVICEREMAPPED,
      fingerdown               = SDL_FINGERDOWN,
      fingerup                 = SDL_FINGERUP,
      fingermotion             = SDL_FINGERMOTION,
      dollargesture            = SDL_DOLLARGESTURE,
      dollarrecord             = SDL_DOLLARRECORD,
      multigesture             = SDL_MULTIGESTURE,
      clipboardupdate          = SDL_CLIPBOARDUPDATE,
      dropfile                 = SDL_DROPFILE,
      droptext                 = SDL_DROPTEXT,
      dropbegin                = SDL_DROPBEGIN,
      dropcomplete             = SDL_DROPCOMPLETE,
      audiodeviceadded         = SDL_AUDIODEVICEADDED,
      audiodeviceremoved       = SDL_AUDIODEVICEREMOVED,
      render_targets_reset     = SDL_RENDER_TARGETS_RESET,
      render_device_reset      = SDL_RENDER_DEVICE_RESET,
      userevent                = SDL_USEREVENT,
      lastevent                = SDL_LASTEVENT
    };

    enum win : uint32_t {
      none         = SDL_WINDOWEVENT_NONE,
      shown        = SDL_WINDOWEVENT_SHOWN,
      hidden       = SDL_WINDOWEVENT_HIDDEN,
      exposed      = SDL_WINDOWEVENT_EXPOSED,
      moved        = SDL_WINDOWEVENT_MOVED,
      resized      = SDL_WINDOWEVENT_RESIZED,
      size_changed = SDL_WINDOWEVENT_SIZE_CHANGED,
      minimized    = SDL_WINDOWEVENT_MINIMIZED,
      maximized    = SDL_WINDOWEVENT_MAXIMIZED,
      restored     = SDL_WINDOWEVENT_RESTORED,
      enter        = SDL_WINDOWEVENT_ENTER,
      leave        = SDL_WINDOWEVENT_LEAVE,
      focus_gained = SDL_WINDOWEVENT_FOCUS_GAINED,
      focus_lost   = SDL_WINDOWEVENT_FOCUS_LOST,
      close        = SDL_WINDOWEVENT_CLOSE,
      take_focus   = SDL_WINDOWEVENT_TAKE_FOCUS,
      hit_test     = SDL_WINDOWEVENT_HIT_TEST
    };
  }

  //////

  enum class pixel_format : uint32_t {
    unknown     = SDL_PIXELFORMAT_UNKNOWN,
    index1lsb   = SDL_PIXELFORMAT_INDEX1LSB,
    index1msb   = SDL_PIXELFORMAT_INDEX1MSB,
    index4lsb   = SDL_PIXELFORMAT_INDEX4LSB,
    index4msb   = SDL_PIXELFORMAT_INDEX4MSB,
    index8      = SDL_PIXELFORMAT_INDEX8,
    rgb332      = SDL_PIXELFORMAT_RGB332,
    rgb444      = SDL_PIXELFORMAT_RGB444,
    rgb555      = SDL_PIXELFORMAT_RGB555,
    bgr555      = SDL_PIXELFORMAT_BGR555,
    argb4444    = SDL_PIXELFORMAT_ARGB4444,
    rgba4444    = SDL_PIXELFORMAT_RGBA4444,
    abgr4444    = SDL_PIXELFORMAT_ABGR4444,
    bgra4444    = SDL_PIXELFORMAT_BGRA4444,
    argb1555    = SDL_PIXELFORMAT_ARGB1555,
    rgba5551    = SDL_PIXELFORMAT_RGBA5551,
    abgr1555    = SDL_PIXELFORMAT_ABGR1555,
    bgra5551    = SDL_PIXELFORMAT_BGRA5551,
    rgb565      = SDL_PIXELFORMAT_RGB565,
    bgr565      = SDL_PIXELFORMAT_BGR565,
    rgb24       = SDL_PIXELFORMAT_RGB24,
    bgr24       = SDL_PIXELFORMAT_BGR24,
    rgb888      = SDL_PIXELFORMAT_RGB888,
    rgbx8888    = SDL_PIXELFORMAT_RGBX8888,
    bgr888      = SDL_PIXELFORMAT_BGR888,
    bgrx8888    = SDL_PIXELFORMAT_BGRX8888,
    argb8888    = SDL_PIXELFORMAT_ARGB8888,
    rgba8888    = SDL_PIXELFORMAT_RGBA8888,
    abgr8888    = SDL_PIXELFORMAT_ABGR8888,
    bgra8888    = SDL_PIXELFORMAT_BGRA8888,
    argb2101010 = SDL_PIXELFORMAT_ARGB2101010,
    rgba32      = SDL_PIXELFORMAT_RGBA32,
    argb32      = SDL_PIXELFORMAT_ARGB32,
    bgra32      = SDL_PIXELFORMAT_BGRA32,
    abgr32      = SDL_PIXELFORMAT_ABGR32,
    yv12        = SDL_PIXELFORMAT_YV12,
    iyuv        = SDL_PIXELFORMAT_IYUV,
    yuy2        = SDL_PIXELFORMAT_YUY2,
    uyvy        = SDL_PIXELFORMAT_UYVY,
    yvyu        = SDL_PIXELFORMAT_YVYU,
    nv12        = SDL_PIXELFORMAT_NV12,
    nv21        = SDL_PIXELFORMAT_NV21
  };

  //////

  enum class flip : uint32_t {
    none       = SDL_FLIP_NONE,
    horizontal = SDL_FLIP_HORIZONTAL,
    vertical   = SDL_FLIP_VERTICAL
  };

  //////

  enum class blend : uint32_t {
    none    = SDL_BLENDMODE_NONE,
    blend   = SDL_BLENDMODE_BLEND,
    add     = SDL_BLENDMODE_ADD,
    mod     = SDL_BLENDMODE_MOD,
    invalid = SDL_BLENDMODE_INVALID
  };

  //////

  struct texture;
  struct window;

  //////

  struct renderer {
    enum class type : uint32_t {
      software      = SDL_RENDERER_SOFTWARE,
      accelerated   = SDL_RENDERER_ACCELERATED,
      presentvsync  = SDL_RENDERER_PRESENTVSYNC,
      targettexture = SDL_RENDERER_TARGETTEXTURE
    };
    renderer(SDL_Window* w, int index, renderer::type type);
    ~renderer();

    int clear() noexcept;
    void present() const noexcept;
    void draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) const noexcept;
    void draw_color(color const& col) const noexcept;
    void fill(rect const& r) const noexcept;
    void fill(rect const* p, int count) const noexcept;
    int copy(texture& t, rect const& src, rect const& dst) noexcept;
    int copy(texture& t, rect const* src = nullptr, rect const* dst = nullptr) noexcept;
    int copy_ex(texture& t, rect const* src = nullptr, rect const* dst = nullptr, double angle = 0,
                point const* center = nullptr, flip fl = flip::none) noexcept;

    SDL_Renderer* get() const noexcept;

   private:
    SDL_Renderer* const p_;
  };

  //////

  struct window {
    enum type : uint32_t {
      fullscreen         = SDL_WINDOW_FULLSCREEN,
      opengl             = SDL_WINDOW_OPENGL,
      shown              = SDL_WINDOW_SHOWN,
      hidden             = SDL_WINDOW_HIDDEN,
      borderless         = SDL_WINDOW_BORDERLESS,
      resizable          = SDL_WINDOW_RESIZABLE,
      minimized          = SDL_WINDOW_MINIMIZED,
      maximized          = SDL_WINDOW_MAXIMIZED,
      input_grabbed      = SDL_WINDOW_INPUT_GRABBED,
      input_focus        = SDL_WINDOW_INPUT_FOCUS,
      mouse_focus        = SDL_WINDOW_MOUSE_FOCUS,
      fullscreen_desktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
      foreign            = SDL_WINDOW_FOREIGN,
      allow_highdpi      = SDL_WINDOW_ALLOW_HIGHDPI,
      mouse_capture      = SDL_WINDOW_MOUSE_CAPTURE,
      always_on_top      = SDL_WINDOW_ALWAYS_ON_TOP,
      skip_taskbar       = SDL_WINDOW_SKIP_TASKBAR,
      utility            = SDL_WINDOW_UTILITY,
      tooltip            = SDL_WINDOW_TOOLTIP,
      popup_menu         = SDL_WINDOW_POPUP_MENU,
      vulkan             = SDL_WINDOW_VULKAN
    };
    static auto const npos     = SDL_WINDOWPOS_UNDEFINED;
    static auto const centered = SDL_WINDOWPOS_CENTERED;

    window(char const* title, int x, int y, int w, int h, window::type flags = window::shown,
           renderer::type renderer_type = renderer::type::accelerated);
    window(char const* title, int w, int h, window::type flags = (window::type)0,
           renderer::type renderer_type = renderer::type::accelerated);
    ~window();

    // renderer const& render() const noexcept;
    renderer& render() noexcept;

    point position() const noexcept;
    void position(int x, int y) noexcept;
    void position(point const& p) noexcept;

    SDL_Window* get() const noexcept;
    SDL_Renderer* get_render() const noexcept;

   private:
    SDL_Window* create(char const* title, int x, int y, int w, int h, uint32_t flags);

    SDL_Window* const p_;
    renderer r_;
  };

  //////

  struct texture {
    static auto const access_static    = SDL_TEXTUREACCESS_STATIC;
    static auto const access_streaming = SDL_TEXTUREACCESS_STREAMING;
    static auto const access_target    = SDL_TEXTUREACCESS_TARGET;

    texture(renderer& r, int w, int h, pixel_format pf = pixel_format::argb8888,
            int access = access_target);
    texture(renderer& r, char const* file);
    texture(renderer& r, char const* file, color const& key);

    bool load(renderer& r, char const* file) noexcept;
    bool load(renderer& r, char const* file, color const& key) noexcept;

    point size() const noexcept;
    rect rect() const noexcept;
    color color_mod() const noexcept;
    void color_mod(color const& c) noexcept;

    uint32_t blend_mode() const noexcept;
    void blend_mode(uint32_t mode) noexcept;

    SDL_Texture* get() const noexcept;

   private:
    bool load_impl(renderer& r, char const* file, color const& key, bool use_key = false) noexcept;

    struct deleter {
      void operator()(SDL_Texture* p);
    };

    std::unique_ptr<SDL_Texture, deleter> p_;
  };

  //////

  inline bool poll_event(event& e) noexcept { return SDL_PollEvent(&e) != 0; }
  inline void pump_events() noexcept { SDL_PumpEvents(); }
  inline int push_event(event& e) noexcept { return SDL_PushEvent(&e); }
  inline bool wait_event(event& e) noexcept { return SDL_WaitEvent(&e) != 0; }
  inline bool wait_timeout_event(event& e, int timeout) noexcept {
    return SDL_WaitEventTimeout(&e, timeout) != 0;
  }

  template <typename... T>
  inline void flush_event(T... types) noexcept {
    (SDL_FlushEvent(types), ...);
  }
  inline void flush_events(uint32_t min, uint32_t max) noexcept { SDL_FlushEvents(min, max); }

  template <typename... T>
  inline bool has_event(T... types) noexcept {
    return ((SDL_HasEvent(types) == 1) && ...);
  }
  inline bool has__events(uint32_t min, uint32_t max) noexcept {
    return SDL_HasEvents(min, max) == 1;
  }

  inline uint8_t event_state(uint32_t type, int state) noexcept {
    return SDL_EventState(type, state);
  }
  inline bool event_state(uint32_t type) noexcept { return SDL_GetEventState(type) == SDL_ENABLE; }

  inline bool quit_requested() noexcept { return SDL_QuitRequested(); }

  //////

  inline renderer::renderer(SDL_Window* w, int index, renderer::type type)
    : p_(SDL_CreateRenderer(w, index, static_cast<uint32_t>(type))) {
    if (p_ == nullptr) throw std::runtime_error(SDL_GetError());
  }
  inline renderer::~renderer() {
    if (p_ != nullptr) SDL_DestroyRenderer(p_);
  }

  inline int renderer::clear() noexcept { return SDL_RenderClear(p_); }
  inline void renderer::present() const noexcept { SDL_RenderPresent(p_); }
  inline void renderer::draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const noexcept {
    SDL_SetRenderDrawColor(p_, r, g, b, a);
  }
  inline void renderer::draw_color(color const& col) const noexcept {
    SDL_SetRenderDrawColor(p_, col.r, col.g, col.b, col.a);
  }

  inline void renderer::fill(rect const& r) const noexcept { SDL_RenderFillRect(p_, &r); }
  inline void renderer::fill(rect const* p, int count) const noexcept {
    SDL_RenderFillRects(p_, p, count);
  }

  inline int renderer::copy(texture& t, rect const& src, rect const& dst) noexcept {
    return SDL_RenderCopy(p_, t.get(), &src, &dst);
  }
  inline int renderer::copy(texture& t, rect const* src, rect const* dst) noexcept {
    return SDL_RenderCopy(p_, t.get(), src, dst);
  }
  inline int renderer::copy_ex(texture& t, rect const* src, rect const* dst, double angle,
                               point const* center, flip fl) noexcept {
    return SDL_RenderCopyEx(p_, t.get(), src, dst, angle, center,
                            static_cast<SDL_RendererFlip>(fl));
  }

  inline SDL_Renderer* renderer::get() const noexcept { return p_; }

  //////

  inline window::window(char const* title, int x, int y, int w, int h, window::type flags,
                        renderer::type render_type)
    : p_(create(title, x, y, w, h, flags))
    , r_(p_, -1, render_type) {}

  inline window::window(char const* title, int w, int h, window::type flags,
                        renderer::type render_type)
    : window(title, npos, npos, w, h, flags, render_type) {}

  inline window::~window() {
    if (p_ != nullptr) SDL_DestroyWindow(p_);
  }

  inline renderer& window::render() noexcept { return r_; }

  inline SDL_Window* window::get() const noexcept { return p_; }
  inline SDL_Renderer* window::get_render() const noexcept { return r_.get(); }

  inline point window::position() const noexcept {
    point p;
    SDL_GetWindowPosition(p_, &p.x, &p.y);
    return p;
  }
  inline void window::position(int x, int y) noexcept { SDL_SetWindowPosition(p_, x, y); }
  inline void window::position(point const& p) noexcept { SDL_SetWindowPosition(p_, p.x, p.y); }

  inline SDL_Window* window::create(char const* title, int x, int y, int w, int h, uint32_t flags) {
    auto p = SDL_CreateWindow(title, x, y, w, h, flags);
    if (p == nullptr) throw std::runtime_error(SDL_GetError());
    return p;
  }

  //////

  inline texture::texture(renderer& r, int w, int h, pixel_format pf, int access)
    : p_(SDL_CreateTexture(r.get(), static_cast<uint32_t>(pf), access, w, h)) {
    if (p_ == nullptr) throw std::runtime_error(SDL_GetError());
  }
  inline texture::texture(renderer& r, char const* file) {
    if (!load(r, file)) throw std::runtime_error(SDL_GetError());
  }
  inline texture::texture(renderer& r, char const* file, color const& key) {
    if (!load(r, file, key)) throw std::runtime_error(SDL_GetError());
  }

  inline bool texture::load_impl(renderer& r, char const* file, color const& key,
                                 bool use_key) noexcept {
    SDL_Surface* s = IMG_Load(file);
    if (s == nullptr) {
      p_.reset();
      return false;
    }
    if (use_key) SDL_SetColorKey(s, SDL_TRUE, SDL_MapRGB(s->format, key.r, key.g, key.b));
    p_.reset(SDL_CreateTextureFromSurface(r.get(), s));
    SDL_FreeSurface(s);
    return true;
  }
  inline bool texture::load(renderer& r, char const* file) noexcept {
    return load_impl(r, file, {}, false);
  }
  inline bool texture::load(renderer& r, char const* file, color const& key) noexcept {
    return load_impl(r, file, key, true);
  }

  inline point texture::size() const noexcept {
    point p;
    SDL_QueryTexture(p_.get(), nullptr, nullptr, &p.x, &p.y);
    return p;
  }
  inline rect texture::rect() const noexcept {
    point p;
    SDL_QueryTexture(p_.get(), nullptr, nullptr, &p.x, &p.y);
    return {0, 0, p.x, p.y};
  }

  inline color texture::color_mod() const noexcept {
    color c;
    SDL_GetTextureColorMod(p_.get(), &c.r, &c.g, &c.b);
    SDL_GetTextureAlphaMod(p_.get(), &c.a);
    return c;
  }
  inline void texture::color_mod(color const& c) noexcept {
    SDL_SetTextureColorMod(p_.get(), c.r, c.g, c.b);
    SDL_SetTextureAlphaMod(p_.get(), c.a);
  }

  inline uint32_t texture::blend_mode() const noexcept {
    SDL_BlendMode m;
    SDL_GetTextureBlendMode(p_.get(), &m);
    return m;
  }
  inline void texture::blend_mode(uint32_t mode) noexcept {
    SDL_SetTextureBlendMode(p_.get(), static_cast<SDL_BlendMode>(mode));
  }

  inline SDL_Texture* texture::get() const noexcept { return p_.get(); }

  inline void texture::deleter::operator()(SDL_Texture* p) {
    if (p != nullptr) SDL_DestroyTexture(p);
  }

  //////
}
