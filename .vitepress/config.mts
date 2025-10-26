import { defineConfig } from "vitepress";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "✨ School Resources",
  description:
    "A collection of educational materials and resources for various subjects and courses related to all my school work.",
  base: "/school/",
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [{ text: "Home", link: "/" }],

    sidebar: [
      {
        base: "/",
        text: "Subjects",
        items: [
          {
            text: "Design of Mechanisms Assisted by Computer",
            link: "/subjects/design-of-mechanisms-assisted-by-computer",
          },
        ],
      },
    ],

    socialLinks: [
      { icon: "github", link: "https://github.com/fermeridamagni/school" },
    ],

    footer: {
      message: "Released under the Apache-2.0 License.",
      copyright: `Copyright © ${new Date().getFullYear()} fermeridamagni`,
    },

    search: {
      provider: "local",
    },
  },
  markdown: {
    lineNumbers: true,
    theme: {
      light: "github-light",
      dark: "github-dark",
    },
  },
});
