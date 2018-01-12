# Base C++ project

make project with `make`

make unit tests with `make tests`

all binaries dropped in `./bin`

recommend running tests before commit using pre-push git hook:

```
#!/bin/sh
./run-tests
results=$?
if [ $results -eq 1 ]; then
  echo -e "${red}\n Tests FAILED\n\n commit aborted${reset}"
  exit 1
else
  echo "${green}\nOK\n${reset}"
fi
exit 0
```
tests require CppUnit: `sudo apt-get install libcppunit-dev`
