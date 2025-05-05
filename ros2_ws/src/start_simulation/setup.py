from setuptools import setup
import os
from glob import glob

package_name = 'start_simulation'

setup(
    name=package_name,
    version='0.0.1',
    packages=[],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/start_simulation']),
	('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.py')),  # Ensures launch files are included
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Sara Francavilla',
    maintainer_email='sara.francavilla@gmail.com',
    description='Package to start arm detection, planning and motion',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [],
    },
)

