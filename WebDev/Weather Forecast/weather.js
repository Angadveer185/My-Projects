let currentweather = new Audio();

async function checkWeather(inpcity) {
    const apiKey = "a553d0145d1e785a0415b1f1a5bec795";
    const apiUrl = `https://api.openweathermap.org/data/2.5/weather?&units=metric&q=${inpcity}`;
    const forecastUrl = `api.openweathermap.org/data/2.5/forecast/daily?q={city name}&cnt={cnt}&appid={API key}`

    const response = await fetch(apiUrl + `&appid=${apiKey}`);
    if (response.status == 404) {
        document.querySelector(".error").style.display = "block";
        document.querySelector(".weather-display").style.display = "none";
    }
    else{
        document.querySelector(".error").style.display = "none";
        document.querySelector(".weather-display").style.display = "block";
    }
    var data = await response.json();

    document.querySelector(".city").innerHTML = data.name;
    document.querySelector(".temp").innerHTML = Math.ceil(data.main.temp) + "°C";
    document.querySelector(".humidity").innerHTML = data.main.humidity + "%";
    document.querySelector(".wind").innerHTML = (data.wind.speed * 3.6).toFixed(2) + " Km/h";
    document.querySelector(
        ".weather-icon"
    ).src = `assets/images/${data.weather[0].main}.png`;
    
    currentweather.src = `assets/videos/${data.weather[0].main}.mp3`;
    currentweather.play();
    console.log(data);
}

document.querySelector(".searchBtn").addEventListener("click", function(){
    let mycity = document.querySelector("#search").value;
    console.log(mycity);
    checkWeather(mycity);

    document.querySelector("#search").value = "";
    
});

document.querySelector(".mode").addEventListener("click", () => {
    document.querySelector("body").classList.toggle("dark");

    if (document.querySelector(".modeImg").src.includes("light")) {
        document.querySelector(".modeImg").src = "assets/images/dark.svg";
    }
    else{
        document.querySelector(".modeImg").src = "assets/images/light.svg";
    }
  
}
)

document.querySelector(".volume").addEventListener("click", () => {

    if (document.querySelector(".volImg").src.includes("volume")) {
        document.querySelector(".volImg").src = "assets/images/mute.svg";
        currentweather.volume = 0;
    }
    else{
        document.querySelector(".volImg").src = "assets/images/volume.svg";
        currentweather.volume = 1;
    }
  
}
)
// let mycity = "new york";
// checkWeather(mycity);