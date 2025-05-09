console.log("Running...");

let currentsong = new Audio();
let songs;
let currFolder;

function secondsToMinutesSeconds(seconds) {
  if (isNaN(seconds) || seconds < 0) {
    return "00:00";
  }

  const minutes = Math.floor(seconds / 60);
  const remainingSeconds = Math.floor(seconds % 60);

  const formattedMinutes = String(minutes).padStart(2, "0");
  const formattedSeconds = String(remainingSeconds).padStart(2, "0");

  return `${formattedMinutes}:${formattedSeconds}`;
}

async function getSongs(folder) {
  currFolder = folder;
  let a = await fetch(`http://127.0.0.1:3000/MySpotify/${folder}/`);
  let response = await a.text();
  let div = document.createElement("div");
  div.innerHTML = response;
  let as = div.getElementsByTagName("a");

  songs = [];

  for (let index = 0; index < as.length; index++) {
    const element = as[index];
    if (element.href.endsWith(".mp3")) {
      songs.push(element.href.split(`/${folder}/`)[1].replace(".mp3", "")); // Remove .mp3 here
    }
  }

  let songUL = document
    .querySelector(".songList")
    .getElementsByTagName("ul")[0];
  songUL.innerHTML = "";
  for (const song of songs) {
    songUL.innerHTML += `<li>
                <img class="invert" src="assets/img/music.svg" alt="" />
                <div class="info">
                  <div>${song
                    .replaceAll("%20", " ")
                    .replaceAll(".mp3", " ")}</div>
                  <div>Angadveer</div>
                </div>

                <div class="playnow">
                  <span>Play Now</span>
                  <img class="invert" src="assets/img/play.svg" alt="" />
                </div>
              </li>`;
  }

  Array.from(
    document.querySelector(".songList").getElementsByTagName("li")
  ).forEach((e) => {
    e.addEventListener("click", (element) => {
      playMusic(e.querySelector(".info").firstElementChild.innerHTML.trim());
    });
  });

  return songs;
}

async function displayAlbums() {
  let a = await fetch(`http://127.0.0.1:3000/MySpotify/songs/`);
  let response = await a.text();
  let div = document.createElement("div");
  div.innerHTML = response;
  let anchors = div.getElementsByTagName("a");
  let cardContainer = document.querySelector(".cardContainer");

  let array = Array.from(anchors);
  for (let index = 0; index < array.length; index++) {
    const e = array[index];
    if (e.href.includes("/songs")) {
      let folder = e.href.split("/").slice(-2)[0];
      let a = await fetch(
        `http://127.0.0.1:3000/MySpotify/songs/${folder}/info.json`
      );
      let response = await a.json();
      cardContainer.innerHTML =
        cardContainer.innerHTML +
        `<div data-folder='${folder}' class="card">
              <div class="play">
                <svg
                  width="24"
                  height="24"
                  viewBox="0 0 24 24"
                  fill="none"
                  xmlns="http://www.w3.org/2000/svg"
                >
                  <path
                    d="M5 20V4L19 12L5 20Z"
                    stroke="#141B34"
                    fill="#000"
                    stroke-width="1."
                    stroke-linejoin="round"
                  />
                </svg>
              </div>
              <img src="/MySpotify/songs/${folder}/cover.jpg" alt="" />
              <h2>${response.title}</h2>
              <p>${response.description}</p>
            </div>`;
    }
  }

  Array.from(document.getElementsByClassName("card")).forEach((e) => {
    e.addEventListener("click", async (item) => {
      songs = await getSongs(`songs/${item.currentTarget.dataset.folder}`);
      playMusic(songs[0]);
    });
  });
}

const playMusic = (track, pause = false) => {
  currentsong.src = `/MySpotify/${currFolder}/` + track + ".mp3"; // Add .mp3 here only
  currentsong.play();
  if (!pause) {
    currentsong.play();
    play.src = "assets/img/pause.svg";
  }
  document.querySelector(".songinfo").innerHTML = decodeURI(
    track.replaceAll(".mp3", " ")
  );
  document.querySelector(".songtime").innerHTML = "00:00 / 00:00";
};

async function main() {
  await getSongs("songs/punjabi");
  playMusic(songs[0]);

  displayAlbums();

  play.addEventListener("click", () => {
    console.log("Play clicked");

    if (currentsong.paused) {
      currentsong.play();
      play.src = "assets/img/pause.svg";
    } else {
      currentsong.pause();
      play.src = "assets/img/play.svg";
    }
  });

  currentsong.addEventListener("timeupdate", () => {
    document.querySelector(".songtime").innerHTML = `${secondsToMinutesSeconds(
      currentsong.currentTime
    )} / ${secondsToMinutesSeconds(currentsong.duration)}`;
    document.querySelector(".circle").style.left =
      (currentsong.currentTime / currentsong.duration) * 100 + "%";
  });

  document.querySelector(".seekbar").addEventListener("click", (e) => {
    console.log("Seekbar clicked");

    let percent = (e.offsetX / e.target.getBoundingClientRect().width) * 100;
    document.querySelector(".circle").style.left = percent + "%";

    currentsong.currentTime = (currentsong.duration * percent) / 100;
  });

  document.querySelector(".hamburger").addEventListener("click", () => {
    document.querySelector(".left").style.left = "0";
  });

  document.querySelector(".close").addEventListener("click", () => {
    document.querySelector(".left").style.left = "-120%";
  });

  previous.addEventListener("click", () => {
    console.log("Previous song is playing");
    currentsong.pause();
    let index = songs.indexOf(
      currentsong.src.split("/").slice(-1)[0].replace(".mp3", "")
    );
    if (index - 1 >= 0) {
      playMusic(songs[index - 1]);
    }
  });

  next.addEventListener("click", () => {
    console.log("Next song is playing");

    currentsong.pause();
    let index = songs.indexOf(
      currentsong.src.split("/").slice(-1)[0].replace(".mp3", "")
    );
    if (index + 1 < songs.length) {
      // Use songs.length here
      playMusic(songs[index + 1]);
    }
  });

  document
    .querySelector(".range")
    .getElementsByTagName("input")[0]
    .addEventListener("change", (e) => {
      currentsong.volume = parseInt(e.target.value) / 100;
    });

  document.querySelector(".volume>img").addEventListener("click", (e) => {
    if (e.target.src.includes("volume.svg")) {
      e.target.src = e.target.src.replace("volume.svg", "mute.svg");
      currentsong.volume = 0;
      document
        .querySelector(".range")
        .getElementsByTagName("input")[0].value = 0;
    } else {
      e.target.src = e.target.src.replace("mute.svg", "volume.svg");
      currentsong.volume = 0.1;
      document
        .querySelector(".range")
        .getElementsByTagName("input")[0].value = 10;
    }
  });
}


main();
