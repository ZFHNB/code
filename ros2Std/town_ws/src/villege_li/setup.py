from setuptools import find_packages, setup

package_name = 'villege_li'

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
    maintainer='zfh',
    maintainer_email='2795337322@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "li4_node_pop=villege_li.li4_pop:main",
            "li4_node_oop=villege_li.li4_oop:main"
        ],
    },
)
