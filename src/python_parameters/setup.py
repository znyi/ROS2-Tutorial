from setuptools import setup

import os #
from glob import glob #

package_name = 'python_parameters'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*launch.[pxy][yma]*')), # to include all launch files
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='malacoda',
    maintainer_email='xinyi2709@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'py_minimal_param_node = python_parameters.python_parameters_node:main' #execute using py_minimal_param_node, but the actual name of the node is still minimal_param_node (as declared in the MinimalParameter class)
        ],
    },
)
