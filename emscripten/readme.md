# Readme
Run docker image using
```
docker-compose -p emscripten -f docker-compose-ubuntu.yml up -d
```

Run with image rebuild
```
docker-compose -p emscripten -f docker-compose-ubuntu.yml up -d --build emscripten
```
Connect to docker container:
```
ssh localhost -l root -p 222
```
To remove old host identification
```
ssh-keygen -R '[hostname]:port' i.e. ssh-keygen -R '[localhost]:222'
```