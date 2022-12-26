const char controlPage[] PROGMEM =
R"=====(
<header>
        <link href="https://fonts.googleapis.com/css2?family=Lato&display=swap" rel="stylesheet">
     </header>
     
     <h1>Micro Submarine</h1>
     <p>Control Test!</p>
     <div class="frame">
        <button onclick="button_ve('NA')" class="custom-btn btn-12"><span>UP!</span><span>NAIK</span></button>
       <button onclick="button_ve('TU')" class="custom-btn btn-7"><span>TURUN</span></button>
       <button onclick="button_he('MA')" class="custom-btn btn-13">MAJU</button>
       <button onclick="button_he('MU')" class="custom-btn btn-14">MUNDUR</button>
       <button onclick="button_stop()" class="custom-btn btn-11">BERHENTI!<div class="dot"></div></button>
       <p style="font-family: Andale Mono, monospace;">
         KELOMPOK 1 | MAGISTER TEKNIK ELEKTRO STEI ITB</p>
         <br>Status Horizontal:<span id="status_horizontal"></span>
         <br>Status Vertical:<span id="status_vertical"></span>
         <br>Jarak Ke Dasar:<span id="jarak_dasar"></span> mm
         <br>Battery:<span id="battery"></span> V
     </div>
)=====";