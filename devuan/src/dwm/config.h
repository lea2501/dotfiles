/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_black[]       = "#000000";
static const char col_violet[]	    = "#8f00ff";
static const char col_pink[]	    = "#ff00f0";
static const char *colors[][3]      = {
	/*               fg         bg          border   */
	[SchemeNorm] = { col_pink,  col_black,  col_gray2 },
	[SchemeSel]  = { col_gray4, col_violet, col_violet  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance    title       tags mask     isfloating   monitor */
	{ "Tor Browser",	NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Mozilla Firefox",	NULL,       NULL,       1 << 1,       0,           -1 },
	{ "keepassxc",		NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Chromium",		NULL,       NULL,       1 << 2,       0,           -1 },
	{ "scrcpy",		NULL,       NULL,       1 << 3,       0,           -1 },
	{ "jetbrains-idea-ce",	NULL,       NULL,       1 << 4,       0,           -1 },
	{ "JDownloader",	NULL,       NULL,       1 << 6,       0,           -1 },
	{ "Transmission-gtk",	NULL,       NULL,       1 << 6,       0,           -1 },
	{ "Amule",		NULL,       NULL,       1 << 6,       0,           -1 },
	{ "appium-desktop",	NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[M]",      monocle },
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_pink, "-sb", col_violet, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", "-f", "Dejavu sans mono:pixelsize=12:antialias=true:autohint=false", NULL };
static const char *termcmdalt[]  = { "st", "-f", "Dejavu sans mono:pixelsize=32:antialias=true:autohint=false", NULL };
static const char *pavdown[]  = { "pactl", "set-sink-volume", "1", "-5%", NULL };
static const char *pavup[]  = { "pactl", "set-sink-volume", "1", "+5%", NULL };
static const char *amixerdown[] = { "amixer", "-q", "sset", "Master", "5%-", NULL };
static const char *amixerup[] = { "amixer", "-q", "sset", "Master", "5%+", NULL };
static const char *brightnessdown[] = { "brightnessctl", "set", "5%-", NULL };
static const char *brightnessup[] = { "brightnessctl", "set", "+5%", NULL };
static const char *lock[] = { "slock", NULL };
static const char *scrot[] = { "scrot", "-s", "-f", NULL };
static const char *dmenubookmarks[] = { "./src/scripts/dmenu_bookmarks.sh", NULL };
static const char *dmenubookmarksnoscript[] = { "./src/scripts/dmenu_bookmarks_noscript.sh", NULL };
static const char *browser[] = { "surf", "-bdfgIS", "www.startpage.com", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,		XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask|ControlMask,	XK_Return, spawn,          {.v = termcmdalt } },
	{ MODKEY|ShiftMask,             XK_F5,     spawn,          {.v = pavdown } },
	{ MODKEY|ShiftMask,             XK_F6,     spawn,          {.v = pavup } },
	{ MODKEY|ShiftMask,             XK_F7,	   spawn,          {.v = brightnessdown } },
	{ MODKEY|ShiftMask,             XK_F8,     spawn,          {.v = brightnessup } },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          {.v = lock } },
	{ MODKEY|ShiftMask,             XK_F12,    spawn,          {.v = scrot } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = browser } },
	{ MODKEY|ShiftMask,             XK_o,      spawn,          {.v = dmenubookmarks } },
	{ MODKEY|ControlMask,           XK_o,      spawn,          {.v = dmenubookmarksnoscript } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

