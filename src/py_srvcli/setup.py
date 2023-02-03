from setuptools import setup

package_name = 'py_srvcli'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
            'pyservice = py_srvcli.service_member_function:main',
            'pyclient = py_srvcli.client_member_function:main',
        ],
    },
)
