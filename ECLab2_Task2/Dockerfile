# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY main.c .
# Compile the C program
RUN gcc -o main main.c
# Set the command to run when the container starts
CMD ["./main"]