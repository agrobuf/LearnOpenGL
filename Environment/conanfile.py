from conan import ConanFile
from conan.tools.cmake import cmake_layout
from conan.tools.system.package_manager import Apt
# TODO: Need to do something with setting the default package manager becuase
# conan doesn't recognize pop as ubuntu

class LearnOpenGLReceipe(ConanFile):
    settings = ("os", "build_type", "arch", "compiler")
    generators = ("CMakeToolchain", "CMakeDeps")

    def requirements(self):
        self.requires("opengl/system")
        self.requires("glfw/[>=3.3.8]")

    def build_requirements(self):
        self.tool_requires("cmake/[>=3.28]")

    def system_requirements(self):
        pass

    def layout(self):
        cmake_layout(self)
