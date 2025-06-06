import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='motion',
            executable='kinematics_node',
            name='kinematics_node',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),
        #launch_ros.actions.Node(
        #    package='motion',
        #    executable='inverse_kin_server_node',
        #    name='inverse_kin_server',
        #    output='screen',
        #    parameters=[{'use_sim_time': True}]
        #),
        #launch_ros.actions.Node(
        #    package='motion',
        #    executable='direct_kin_server',
        #    name='direct_kin_server',
        #    output='screen',
        #    parameters=[{'use_sim_time': True}]
        #),
        launch_ros.actions.Node(
            package='motion',
            executable='compute_trajectory',
            name='compute_trajectory',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),
        launch_ros.actions.Node(
            package='motion',
            executable='compute_path',
            name='compute_path',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),
    ])
