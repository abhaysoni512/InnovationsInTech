1. What is Docker ?
Docker is platform which helps to create docker container

2. What is Docker Container?
A Docker Container is a container which contains application + dependencies.

3. Properties of Docker:
    i. Portable
    ii. Light weight
    iii. bhut sare verions use kr skte h in a single container

3.5 Docker Basics:
    i. To pull docker image
        docker pull <image_name>
    ii to search docker image
        docker search <image_name>

    iv. 
        docker run --name pyhtonRun -d a4b2b11a9faf

    v. 
        abhaysoni512 ~ % docker run --name pyhtonRun -d a4b2b11a9faf
        baaf050daa9554f361237902cc27a56791d737f9955af240782cae9c658f887e
        abhaysoni512 ~ % docker ps
        CONTAINER ID   IMAGE     COMMAND       CREATED       STATUS          PORTS     NAMES
        35de4eb7f651   ubuntu    "/bin/bash"   7 weeks ago   Up 57 minutes             strange_wozniak
        abhaysoni512 ~ % docker run --name pyhtonRun -it -d python          
        docker: Error response from daemon: Conflict. The container name "/pyhtonRun" is already in use by container "baaf050daa9554f361237902cc27a56791d737f9955af240782cae9c658f887e". You have to remove (or rename) that container to be able to reuse that name.

        Run 'docker run --help' for more information
        abhaysoni512 ~ % docker run --name pyhtonRunIT -it -d python
        ce3223d6d6fdbcdcf09f49f32ffb8e275e9d6b963941a134abce2ba74b256904
        abhaysoni512 ~ % ps
        PID TTY           TIME CMD
        20168 ttys002    0:00.52 -zsh
        20368 ttys003    0:00.09 /bin/zsh -il
        abhaysoni512 ~ % docker ps
        CONTAINER ID   IMAGE     COMMAND       CREATED         STATUS          PORTS     NAMES
        ce3223d6d6fd   python    "python3"     8 seconds ago   Up 8 seconds              pyhtonRunIT
        35de4eb7f651   ubuntu    "/bin/bash"   7 weeks ago     Up 58 minutes             strange_wozniak

    -it is used to run docker container in interactive mode
    -d is used to run docker container in detached mode
    -p is used to map the port of host machine to the port of docker container

    vi. to run docker container in interactive mode
        docker run --name pyhtonRunIT -it -d python
    vii. to run docker container in interactive mode and with name                  
        docker run --name <container_name> -it -d <image_name>
    viii. to run docker container in interactive mode and with name and port
        docker run --name <container_name> -it -d -p <host_port>:<container_port> <image_name>
    ix. to run docker container in interactive mode and with name and port and volume
        docker run --name <container_name> -it -d -p <host_port>:<container_port> -v <host_path>:<container_path> <image_name>

    


4. What is Docker Image?
Docker Image is executable file which contains recipes to create Docker container

5. Commands To Remember:
   
    i. to show docker image
       docker images
    ii. to show docker container
        docker ps
    iii. to show all docker container
        docker ps -a
    iv. to run docker container
        docker run -it <image_name> /bin/bash
    v. to run docker container in background
        docker run -d <image_name>
    vi. to stop docker container
        docker stop <container_id>
    vii. to remove docker container
        docker rm <container_id>
    viii. to remove docker image
        docker rmi <image_id>
    ix. to remove all docker container
        docker rm $(docker ps -a -q)
    x. to remove all docker images
        docker rmi $(docker images -q)
    xi. to remove all docker images and container
        docker rm $(docker ps -a -q) && docker rmi $(docker images -q)
    xii. to remove all docker images and container forcefully
        docker rm -f $(docker ps -a -q) && docker rmi -f $(docker images -q) 

6. Docker Port:
    i. Docker port is used to map the port of host machine to the port of docker container
    ii. By default docker container runs on 80 port
    iii. To run docker container on different port use -p option
        docker run -d -p <host_port>:<container_port> <image_name>
    iv. To run docker container on different port and in background use -d option
        docker run -d -p <host_port>:<container_port> <image_name>
    v. To run docker container on different port and in background and with name use --name option
        docker run -d -p <host_port>:<container_port> --name <container_name> <image_name>   



