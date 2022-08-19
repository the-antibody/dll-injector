# dll-injector
A GUI/CLI Windows DLL injector in C++.

# About
I can't always rely on Process Hacker 2 for making "realistic" malware that will actually have any affect on someone's PC. No one is going to install third-party software just to run a virus on their PC.<br />
So naturally speaking, of course, I made my own process injection executable that can run by a GUI (practically), or by a CLI (silently).

# Media
![image](https://user-images.githubusercontent.com/71285258/185551999-91ab298b-2f16-4fcb-a50e-41cf04686965.png)

# Installation
To download the injector, click [here](https://github.com/the-antibody/dll-injector/releases/download/1.0.0/install.vbs) and run through the install script.<br />
Once that's done, copy the created directory in your AppData Roaming. (for example, `C:\Users\user\AppData\Roaming\dll-injector`)<br />
Then, hit your Windows key and search `Edit the system environment variables`. Click the `Environment Variables` button at the bottom. Find the variable `Path` under `User variables for [username]`, and click `Edit`. On the new popup window, click `New` and paste the directory you copied.<br />
Once done, click `Ok`, `Ok`, `Apply`, and then `Ok`.<br />
**Now you're finished.**

### Images
![image](https://user-images.githubusercontent.com/71285258/185554513-bde44db1-2109-4505-ab59-cfd410830cf2.png)<br />

**You (might?) have to turn off your AntiVirus product for the executable to work (because Windows Defender doesn't like uncommon executables)**

# Information for Developers

### Languages
 - C++ (Win32 API)
