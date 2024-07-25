from setuptools import find_packages, setup

package_name = 'py_proj'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sunny',
    maintainer_email='sunhyuck98@gmail.com',
    description='TODO: Package description',
    license='Apach-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'publisher = py_proj.proj_coordinate:main',
            'reader = py_proj.proj_data_reader:main',
        ],
    },
)
