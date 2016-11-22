COMMON_CXX_FLAGS = "-std=c++1y -g -ggdb  -fPIC"
ROCKET_LIBS = ['RocketCore', 'RocketControls', 'RocketDebugger', ]
BULLET_LIBS = ['BulletCollision', 'BulletSoftBody', 'BulletDynamics', 'LinearMath']
BOOST_LIBS = ['boost_timer', 'boost_filesystem', 'boost_system', 'boost_thread', 'boost_python', ]
SDL_LIBS = ['SDL2', 'SDL2_ttf', 'SDL2_image', ]
GL_LIBS = ['GL', 'GLEW', 'GLU']
GENERAL_LIBS = ['stdc++', 'pthread', 'python2.7', 'dl', ]
TEST_LIBS = ['gtest' ]
ALL_LIBS = GENERAL_LIBS + BOOST_LIBS + SDL_LIBS + GL_LIBS + BULLET_LIBS + ROCKET_LIBS
CPPATH = [
    '/usr/include/python2.7',
    '/usr/include/bullet',
    './src/ui/librocket_interfaces',
    '/usr/local/include/Rocket',
    '../src/core',
    '../src/io',
]

