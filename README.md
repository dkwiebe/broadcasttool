This is a copy of https://sourceforge.net/projects/butt/. The authors homepage is at http://danielnoethen.de/.  I have this copy here to keep track of a few changes we've been working on.

# butt (0.1.15) Manual 
:author: Daniel Nöthen

:doctype: book

:toc2:

:numbered:

:lang: en

:email: butt at danielnoethen dot de

:encoding: utf-8


# About
butt (broadcast using this tool) is an easy to use, multi OS streaming tool. 
It supports ShoutCast and IceCast and runs on Linux, MacOS and Windows. 
The main purpose of butt is to stream live audio data from your computers Mic or Line input 
to an Shoutcast or Icecast server. Recording is also possible. 
It is NOT intended to be a server by itself or automatically stream a set of audio files. 


# Installing from precompiled packages
## OS X: 
Mount the *butt-<version>.dmg* by double clicking and drop the butt file to the Applications folder. 

## Windows: 
Just run the *butt-<version>-setup.exe* as usual and go through the +
installer pages. +
The default installation path might be unusual, but this way it is possible to install +
butt without administration rights. +

## Ubuntu Linux (and its derivatives):
Before you install butt on Ubuntu, make sure you have the following packages installed on +
your system: 'libportaudio2', 'libvorbis0a', 'libfltk1.3', 'libmp3lame0', 'libflac8', 'libsamplerate0' and +
'libopus0'.

On Ubuntu you can install these packages by running the following command in your terminal: 

`sudo apt-get install libportaudio2 libvorbis0a libfltk1.3 libmp3lame0 libflac8 libsamplerate0 libopus0`


After these packages are successfully installed, you can install the butt package using the 'dpkg' command:

`sudo dpkg --install butt_<version>-0ubuntu1_amd64.deb`



# Installing from source

### Windows
Before butt can be compiled on Windows, you must first download http://www.msys2.org/[MSYS2] and install it. It +
doesn't really matter where it's installed as long as you'll know where to find it. 

After installing it, you will find three different shells in the directory in which *MSYS2* was installed: +
`mingw32.exe`, `mingw64.exe` and `msys2.exe`. Each of these shells predefines a different set of environmental +
variables which determine the architecture of the build. For our purposes we won't need the `msys2.exe` +
shell, we'll only look at `mingw32` (thought which we build 32 bit butt) and `mingw64` (though which we build 64 bit butt). In other words, which shell we use depends on what kind of executable we want to build.


#### Building
To make a *32 bit* build of butt in these four steps:
. run the 'mingw32.exe' shell 
. navigate to the *butt project directory* inside the 'mingw32.exe' shell
. once there run the './win-setup.sh' script to download and configure all dependencies for the 32 bit build
. finally, run './win-make.sh' script to build the project. The compiled project and its '.dll' dependencies are now stored in the 'build/i686' directory inside the butt project directory

Similarly, to make a *64 bit* build of butt we follow the same steps except that this time we use the 'mingw64.exe' shell instead:
. we run the 'mingw64.exe' shell 
. using the shell we navigate to the *butt project directory*
. once there, we run the './win-setup.sh' script to download and configure all dependencies for the 64 bit build
. finally, we run './win-make.sh' script to build the project. The compiled project and its '.dll' dependencies can now be found in the 'build/x86_64' directory inside the butt project directory

[NOTE]
'./win-setup.sh' only needs to be run once in each shell.

[NOTE]
When you start a shell your working directory will be set to a unix style home '/home/{username}'. To navigate away from this directory, simply type 'cd c:', or any other drive letter to go back to a Windows directory.

[IMPORTANT]
If you have already built butt for one architecture and now want to build for another, you must first run 'make clean' command in the project root to clear previously generated objects, otherwise you might have a linking problem if the objects of different architectures get mixed up. 


### Ubuntu Linux
In addition to the packages mentioned above, compiling butt on Ubuntu requires additional development +
packages: 'portaudio19-dev', 'libvorbis-dev', 'libfltk1.3-dev', 'libmp3lame-dev' 'libflac-dev', 'libsamplerate-dev' and 'libopus-dev'

All of these can be installed by running the following command in your terminal:

`sudo apt-get install portaudio19-dev libvorbis-dev libfltk1.3-dev libmp3lame-dev libflac-dev libsamplerate-dev libopus-dev libportaudio2 libvorbis0a libfltk1.3 libmp3lame0 libflac8 libsamplerate0 libopus0`

Now that these packages are installed you can extract the source code archive using the command line:

`tar -xzf butt-<version>.tar.gz`

or you can use a graphical tool of your choice.

After the sources are extracted, navigate to the project root inside your terminal and run the following commands:

`./autogen.sh`

then

`./configure`

then

`make`

to build the project. And finally

`sudo make install`


to install it. This final step is optional. You can still run the `butt` executable from the `src` directory without installing it.


# Quick start
When you start butt the first time, it will create a default configuration +
file in in your home directory ('~/.buttrc') on Linux and OS X or at +
'C:\Users\<username>\AppData\Roaming\buttrc' on Windows. +

In order to connect to a server, you need to add a new server in the config window.  +
Just open the settings window and click on [ADD]. +
Now fill in the input fields with the server data and click on the new [ADD]. +

Adding Stream Infos is not necessary for connecting to a server.


## Configuration
The command line option +-c <path_to_file>+ allows you to define a new standard configuration path.  +
This makes it possible to have multiple instances with different configurations +
running. In case the file does not exists, butt will create a default file. +

[Save]: Saves your current settings to the standard configuration +
file or to the file that was passed to the -c option +
[Export]: Saves your current settings to the given file +
[Import]: Loads the selected file and applies the settings +

CAUTION: If you use the -c command line option and import another configuration file by using the + 
import function, pressing [Save] will overwrite the file that was passed to the -c option.


## Main Window
The dot matrix display shows you the current state of the butt software. +
The states are: idle, streaming, recording. +
When in streaming and/or recording state you can cycle through the information by clicking on the display. +
You can choose between online duration, data sent, recording duration and data recorded +

The [>] symbol shines yellow if butt is connected to a server. +
The [O] symbol shines orange if the +[start rec. when connected]+ checkbox is activated. +
The [O] symbol shines red if butt is currently recording. +

The coloured LED lights (vu-meter) indicate the current input volume.  For best listening experience  +
for you listeners I suggest to have the input volume below or within the orange LEDs.  +
Never let the volume go up to the red LEDs, they indicate saturation. +

Gain slider:
The slider is only visible when the little +[more/less]+ button below  +
the +[settings]+ button was clicked. +
With this slider you can attenuate and amplify the input signal between '-24dB' and  '+24dB', respectively. +
Double clicking the slider resets the gain to '0dB'.  Use this slider only to fine tune your input signal.  +
It does not change the operating systems input volume setting. Instead, the input signal is multiplied +
by the given factor. Thus adding to much gain will also add lots of noise. +


## Streaming
To start streaming just klick the play symbol. +
butt will try to connect to the server until you press the stop symbol. +

You can stream with 3 different codecs: mp3, ogg/vorbis and ogg/opus. + 
In case opus is selected the samplerate is always upsampled to 48kHz. +
Upsampling needs lot of CPU power. You can change the upsampling +
algorithm in the +[Advanced]+ settings on the +[Audio]+ tab. Upsampling + 
is deactivated if you select 48kHz as sample rate.


Unfortunately, it is not possible to update Stream Infos while streaming. +
You need to reconnect for updating the Stream Infos. +

However, at least you can update the current song on the fly. +
You only need to type the song into the +Song Name+ input field at the +
+[Stream]+ tab and hit Enter or click +[OK]+. 

butt can also update the song automatically from a text file. +
The first line of the text file must be the name of the song. +
As soon as butt detects that the file has been changed it updates the +
name of the song on the server. +
A plugin for the amarok audio player can be found in the 'player_plugins/' +
directory. +
Don't hesitate to write a plugin for other audio players. +
Just mail them to me and I'll add them to the butt package. +
 
.Stream infos:
In the +[main]+ settings window you can add stream infos. +
This allows you to deliver more details of your stream station. +
For example the genre of your music, description of your station, web address etc. +


## Recording
butt is able to record and stream simultaneously in different bit rates. +
For example you can stream with 96kbit and record with 192kbit. +
Recording is possible in mp3, ogg/vorbis, ogg/opus, FLAC or wav. 

In case 'opus' is selected the samplerate is always upsampled to +48kHz+. +
Upsampling needs lots of CPU power. You can change the upsampling +
algorithm in the [Advanced] settings on the [Audio] tab or disable it +
by selecting 48kHz as sample rate. Not all sound interfaces support a +
samplerate of 48kHz, though. +


To record you first need to select the destination folder and specify a file name  +
in the +[Rec]+ tab.  +
butt will replace the variables +%d+, +%m+ and +%y+ with the current day, month and year. +
e.g. +rec_(%m_%d_%y).mp3+ -> +rec_(03_28_2008).mp3+. +
Other possible time variables are +%H+ (hours) +%M+ (minutes) +%S+ (seconds).

 
With the +%i+ variable you can add an index number to your file name. +
This means with +rec_%i.mp3+ butt first tries to open +rec_0.mp3+. If that +
file already exists, butt tries +rec_1.mp3+ and so on... +
 
If the 'start recording when connected' checkbox is activated butt starts the +
recording immediately after being connected to a server. +
 
To manually start the recording press the record symbol. +
To stop recording simply click on the record symbol again. +
 
You can also tell butt to split your recording into
separat files every *n* minutes. Just enter a number higher than 0 +
into the 'Split file every [..] minutes' field. +
Let's assume your file name is +rec_(%m_%d_%y)\_%i.mp3+ Then the first file is +
expanded to +rec\_(03_28_2008)\_0-1.mp3+, the second after *n* minutes to +
+rec_(03_28_2008)\_0-2.mp3+, the third to +rec_(03_28_2008)_0-3.mp3+, you got it. +
If the 'sync to full hour' checkbox is activated the automatic file splitting +
is synchronized to the full hour. That means if the time is '8:55' and file +
splitting is set to '15 minutes', the second file starts at '9:00' and the third +
at '9:15'.


## Uninstall
.OS X: 
Delete the *butt.app* from your 'Application' folder and +
remove the configuration file from '/Users/<username>/.buttrc' +

.Windows: 
Run the Uninstaller from the butt folder in your windows start menu. +

.Ubuntu .deb package:
Run +sudo apt-get uninstall butt+ and +
remove the configuration file from '/home/<username>/.buttrc' +

.Linux install from sources: 
Run +sudo make uninstall+ from the source tree. and +
remove the configuration file from '/home/<username>/.buttrc' +


## Contact
butt at danielnoethen dot de


=== Will code for food
Paypal: bipak@gmx.net
