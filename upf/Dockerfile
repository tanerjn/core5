# Use an official C++ runtime as a parent image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container
COPY . .

# Compile the C++ program
RUN g++ -o upf upf.cpp

# Run the compiled program by default when the container starts
CMD ["./upf"]

