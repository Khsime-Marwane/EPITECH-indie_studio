# THE BOMBTLET
![N|Solid](https://mobilegamegraphics.com/pvpaterno/GIF/wizard_attack.gif)

  - ###### A mix between Gauntlet and Bomberman.
  - ###### A 3D multiplayer video game.
  - ###### Magic
  - ###### Cross-Platerform

### Techs

##### * [C++]
##### * [Python / Lua]

### Dependencies
The project uses a number of open source projects to work properly:
##### * [Irrlicht](http://irrlicht.sourceforge.net/)
##### * [CEGUI](http://cegui.org.uk/)
##### * [OPENAL](https://openal.org/)
##### * [SNDFILE](http://www.mega-nerd.com/libsndfile/)


# Installation

Bombtlet requires updating your graphics drivers if this is not done.

### For Linux
Install the dependencies.
```sh
$ make install
```
Build from sources:
```sh
$ make build
```

### For Windows
in progress..

### Docker
Bauntlet is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 80, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
docker build -t marwane-khsime/bauntlet:${package.json.version}
```
This will create the bauntlet image and pull in the necessary dependencies. Be sure to swap out `${package.json.version}` with the actual version of Bauntlet.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 80 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/bauntlet:${package.json.version}
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
ping localhost:8000
```

License
----



*This project was realized as part of my school program at Epitech in my second year, in collaboration with Samuel Da-fonseca, Sebastien Jacobin, Romain Samuel, Rida Baba and Maud Marel. This project is free to use.*

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
