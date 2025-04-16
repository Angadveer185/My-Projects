document.addEventListener("DOMContentLoaded", () => {
  if (localStorage.getItem("task") != null) {
    document.querySelector(
      ".lst"
    ).innerHTML += `<li class = "listitem">${localStorage.getItem(
      "task"
    )}</li>`;
    document.querySelector(".info").style.display = "none";
  }
});

child = document.querySelector(".lst").children;
if (child.length == 0) {
  document.querySelector(".info").style.display = "block";
}

document.querySelector(".enter").addEventListener("click", () => {
  task = document.querySelector("#task").value.trim();
  console.log(task);
  if (task != "") {
    let list = document.querySelector(".lst");
    document.querySelector(
      ".lst"
    ).innerHTML += `<li class = "listitem">${task}</li>`;
    localStorage.setItem("task", task);
    document.querySelector(".info").style.display = "none";
    document.querySelector("#task").value = "";

    child = document.querySelector(".lst").children;
    console.log(child);

    document.querySelector(".error").style.display = "none";
  } else {
    document.querySelector(".error").style.display = "block";
  }
});

document.querySelector(".lst").addEventListener("click", (e) => {
  if (e.target.classList.contains("listitem")) {
    e.target.remove();
    child = document.querySelector(".lst").children;
    if (child.length == 0) {
      document.querySelector(".info").style.display = "block";
    }
  }
});

mode = document.querySelector(".mode");
modeImg = document.querySelector(".modeImg");
mode.addEventListener("click", () => {
  document.body.classList.toggle("light");

  if (modeImg.src.includes("sun")) {
    modeImg.src = "assets/images/moon.svg";
  } else {
    modeImg.src = "assets/images/sun.svg";
  }
});
