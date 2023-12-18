/* ************************************************************************
 *
 * Copyright (C) 2022 Vincent Luo All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, e1ither express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ************************************************************************/

/* Creates on 2022/9/14. */

/*
  ===================================
    @author bit-fashion
  ===================================
*/
#include "Window.h"

Window::Window(const String &title, uint32_t width, uint32_t height)
  : m_Title(std::move(title)), m_Width(width), m_Height(height) {

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    HWIN = glfwCreateWindow(m_Width, m_Height,_chars(m_Title), null, null);
    if (HWIN == null)
        throw std::runtime_error("Create glfw window failed!");

    glfwSetWindowUserPointer(HWIN, this);

    glfwSetWindowSizeCallback(HWIN, [](GLFWwindow *window, int width, int height) {
        Window *win = (Window *) glfwGetWindowUserPointer(window);
        win->m_Width = width;
        win->m_Height = height;
        win->m_WindowResizeableEventCallback(win, win->m_Width, win->m_Height);
    });
}

Window::~Window() {
    glfwDestroyWindow(HWIN);
    glfwTerminate();
}