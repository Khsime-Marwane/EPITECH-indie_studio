# Use ubuntu image
FROM ubuntu

# Authors
MAINTAINER Samuel Romain <romain.samuel@epitech.eu>
MAINTAINER Khsime Marwane <marwane.khsime@epitech.eu>
MAINTAINER Maud Marel <maud.marel@epitech.eu>
MAINTAINER Samuel Da Fonseca <samuel.da-fonseca@epitech.eu>
MAINTAINER Sebastien Jacobin <sebastien.jacobin@epitech.eu>
MAINTAINER Rida Baba <rida.baba@epitech.eu>

# Install Depedencies
RUN apt-get update
RUN apt-get install -y build-essential apt-utils
RUN apt-get install -y  wget    \
                        git     \
                        gcc     \
                        clang   \
                        g++     \
                        doxygen

# Create the project's folder in the container
RUN mkdir -p /home/Project
# Copy the project in the container
COPY . /home/Project

RUN echo '[OK]'