<p align="center">
  <img align="center" src="https://img.itch.zone/aW1nLzE2MDMyMTUyLnBuZw==/original/j090bt.png">
</p>

Thank you for visiting the GitHub repository! Here you can find the full code for the game and (if you are on a Linux machine) instructions on how to compile it and customize the Kanjis and words.

Please, feel free to visit the [Issues section](https://github.com/MascaChapas27/Kanji-God/issues) if you have any problem that needs to be solved. If you want to download the latest version, go to the [itch.io page](https://mascachapas27.itch.io/kanji-god), or go to [Releases](https://github.com/MascaChapas27/Kanji-God/releases) and choose the latest one (the one at the top).

# Compiling on Linux

In order to compile the program on any Linux machine, follow these instructions:

## 1. Install everything you need

In order to compile Kanji God you need the following programs:

1. git
2. g++
3. make

The installation method depends on the distribution. Try running those commands on `bash`. You might have them installed, or maybe you don't and a line will be displayed, telling you how to install them.

If this line doesn't appear, you usually just need to type:

```bash
sudo apt install git
```
(On Fedora machines, instead of `apt` write `yum`).

## 2. Clone the project

Use the following command to copy the contents of the repository to your machine:

```bash
git clone https://github.com/MascaChapas27/Kanji-God
```

Once the cloning is done, type the following command to navigate to the directory:

```bash
cd Kanji-God
```

## 3. Compile the project

Type `make` to compile the project. If something bad happens, error messages will appear. Please, go to the [Issues section](https://github.com/MascaChapas27/Kanji-God/issues), click on the "New Issue" button and paste the message. I would also appreciate it if you told me what distribution you are using and which version.

## 4. Run the project

Type `make run` to execute the program. It should work if there were no compilation errors during step 3, but anything could happen. Again, if it doesn't work, you can create an Issue and paste the error message you got.

## Typical errors

Sometimes the project will compile properly but won't run because a resource cannot be found. Please make sure that the structure of the project is exactly the same as in the repository: if you change names or move files you may screw everything!!

## Additional: How to customize the files.

TODO
