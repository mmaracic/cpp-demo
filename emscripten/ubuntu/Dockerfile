FROM ubuntu:24.04
ARG ROOT_PASSWORD=password
ENV ROOT_PASSWORD $ROOT_PASSWORD
RUN apt update
RUN apt install bash -y
RUN apt install git-all -y
RUN apt install python3 python3-pip -y
#RUN apt install cmake -y
RUN apt install nano -y

RUN apt install openssh-server -y
RUN echo "root:$ROOT_PASSWORD" | chpasswd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

RUN git clone https://github.com/emscripten-core/emsdk.git
WORKDIR emsdk
RUN ./emsdk install latest
RUN echo "/emsdk/emsdk activate latest && source /emsdk/emsdk_env.sh" > /etc/profile

EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
