from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    ld = LaunchDescription()
    cmd__ = ExecuteProcess(
        cmd = ["source", "install/setup.bash"],
        output = "screen"
    )
    ld.add_action(cmd__)

    node__ = Node(
        package='enemy_estimator_task',
        namespace='enemy_estimator_task',
        executable='enemy_estimator_task',
        output='screen',
        name='enemy_estimator'
    )
    ld.add_action(node__)
    return LaunchDescription