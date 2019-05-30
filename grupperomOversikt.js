/*function() {
  "use strict";
  // Some key codes that are used
  var up = 38,
    down = 40,
    left = 37,
    right = 39,
    A = 65,
    B = 66;
  // Full Konami Code obtained from: http://en.wikipedia.org/wiki/Konami_Code
  var konamiCode = [up, up, down, down, left, right, left, right, B, A];
  // Deteted sequence. Empty by default
  var konamiDetected = [];

  // Attachs the function on an element (for a certain event)
  function attachCustomEvent(el, eventName, desiredFunction) {
    if (el.addEventListener) {
      el.addEventListener(eventName, desiredFunction, false);
      // Old IE
    } else {
      el.attachEvent('on' + eventName, desiredFunction);
    }
  }

  // Detachs the function on an element (for a certain event)
  function detachCustomEvent(el, eventName, desiredFunction) {
    if (el.removeEventListener) {
      el.removeEventListener(eventName, desiredFunction, false);
      // Old IE
    } else {
      el.detachEvent('on' + eventName, desiredFunction);
    }
  }

  // Function that is invoked after detecting the Konami Code
  function startUpKonami() {
    // Prevent further detection (When removing this line the Konami code can be entered multiple times)
    detachCustomEvent(document, "keydown", isKonamiKey);
    konamiIsDetected();
  }

  // Function to detect whether the pressed key is part of the Konami Code
  function isKonamiKey(e) {
    var evt = e || window.event;
    var key = evt.keyCode ? evt.keyCode : evt.which;
    // Set to true before checking everything
    var codeOk = true;
    // Push the key
    konamiDetected.push(key);
    // Check if the key is valid or not
    if (konamiDetected.length < konamiCode.length) {
      // Check that the values are Ok so far. If not clear the array
      for (var i = 0, max = konamiDetected.length; i < max; i++) {
        if (konamiDetected[i] !== konamiCode[i]) {
          codeOk = false;
        }
      }
      if (!codeOk) {
        // Clean the array
        konamiDetected = [];
        // Push the just detected value inside the array
        konamiDetected.push(key);
      }
    } else if (konamiDetected.length === konamiCode.length) {
      for (var j = 0, max = konamiDetected.length; j < max; j++) {
        if (konamiDetected[j] !== konamiCode[j]) {
          codeOk = false;
        }
      }
      // Clean the array
      konamiDetected = [];
      if (codeOk) {
        startUpKonami();
      }
      // This should never happen, but if it happens we clean the array
    } else {
      konamiDetected = [];
    }
    // After everything has been checked show the resulting array after pressing such key
    // console.log(konamiDetected);
  }

  // Attach the event detection to the whole document
  attachCustomEvent(document, "keydown", isKonamiKey);
})();*/

// Function that is invoked after the konami code has been entered
/*function konamiIsDetected() {
  window.location.href = 'https://commons.wikimedia.org/wiki/File:Bg-easter-eggs.jpg';
}*/


// Bla mellom sidene
function side(n) {
  var a, b, c, d = 0;
  a = document.getElementById("Oversikt");
  b = document.getElementById("kart")
  c = document.getElementById("trengerHjelp");
  d = document.getElementById("omP");
  if (n == 1) {
    a.style.display = "block";
    b.style.display = "none";
    c.style.display = "none";
    d.style.display = "none";

    document.getElementById("over").className = "active";
    document.getElementById("kartm").className = "inactive";
    document.getElementById("hjelp").className = "inactive";
    document.getElementById("pro").className = "inactive";
  } else if (n == 2) {
    a.style.display = "none";
    b.style.display = "grid";
    c.style.display = "none";
    d.style.display = "none";
    document.getElementById("over").className = "inactive";
    document.getElementById("kartm").className = "active";
    document.getElementById("hjelp").className = "inactive";
    document.getElementById("pro").className = "inactive";
  } else if (n == 3) {
    a.style.display = "none";
    b.style.display = "none";
    c.style.display = "block";
    d.style.display = "none";
    document.getElementById("over").className = "inactive";
    document.getElementById("kartm").className = "inactive";
    document.getElementById("hjelp").className = "active";
    document.getElementById("pro").className = "inactive";
  } else {
    a.style.display = "none";
    b.style.display = "none";
    c.style.display = "none";
    d.style.display = "block";
    document.getElementById("over").className = "inactive";
    document.getElementById("kartm").className = "inactive";
    document.getElementById("hjelp").className = "inactive";
    document.getElementById("pro").className = "active";
  }
}

// Sorter tabellen
function sortTable(n) {
  var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
  table = document.getElementById("myTable");
  switching = true;
  // Set the sorting direction to ascending:
  dir = "asc";
  /* Make a loop that will continue until
  no switching has been done: */
  while (switching) {
    // Start by saying: no switching is done:
    switching = false;
    rows = table.rows;
    /* Loop through all table rows (except the
    first, which contains table headers): */
    for (i = 1; i < (rows.length - 1); i++) {
      // Start by saying there should be no switching:
      shouldSwitch = false;
      /* Get the two elements you want to compare,
      one from current row and one from the next: */
      x = rows[i].getElementsByTagName("TD")[n];
      y = rows[i + 1].getElementsByTagName("TD")[n];
      /* Check if the two rows should switch place,
      based on the direction, asc or desc: */
      if (dir == "asc") {
        if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {
          // If so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      } else if (dir == "desc") {
        if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {
          // If so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      }
    }
    if (shouldSwitch) {
      /* If a switch has been marked, make the switch
      and mark that a switch has been done: */
      rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
      switching = true;
      // Each time a switch is done, increase this count by 1:
      switchcount++;
    } else {
      /* If no switching has been done AND the direction is "asc",
      set the direction to "desc" and run the while loop again. */
      if (switchcount == 0 && dir == "asc") {
        dir = "desc";
        switching = true;
      }
    }
  }
}

function sortTableLuft(n) {
  var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
  table = document.getElementById("myTable");
  switching = true;
  // Set the sorting direction to ascending:
  dir = "asc";
  /* Make a loop that will continue until
  no switching has been done: */
  while (switching) {
    // Start by saying: no switching is done:
    switching = false;
    rows = table.rows;
    /* Loop through all table rows (except the
    first, which contains table headers): */
    for (i = 1; i < (rows.length - 1); i++) {
      // Start by saying there should be no switching:
      shouldSwitch = false;
      /* Get the two elements you want to compare,
      one from current row and one from the next: */
      x = rows[i].getElementsByTagName("TD")[n];
      y = rows[i + 1].getElementsByTagName("TD")[n];
      /* Check if the two rows should switch place,
      based on the direction, asc or desc: */
      if (dir == "asc") {
        if (Number(x.title) > Number(y.title)) {
          // If so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      } else if (dir == "desc") {
        if (Number(x.title) < Number(y.title)) {
          // If so, mark as a switch and break the loop:
          shouldSwitch = true;
          break;
        }
      }
    }
    if (shouldSwitch) {
      /* If a switch has been marked, make the switch
      and mark that a switch has been done: */
      rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
      switching = true;
      // Each time a switch is done, increase this count by 1:
      switchcount++;
    } else {
      /* If no switching has been done AND the direction is "asc",
      set the direction to "desc" and run the while loop again. */
      if (switchcount == 0 && dir == "asc") {
        dir = "desc";
        switching = true;
      }
    }
  }
}

function luftStatus() {
  sortTableLuft(4);
  sortTable(3);
}

//oppdatere Kart etter tabell
function oppdatereKartDel(id, n) {
  var table, rows, status, boks, LuftKval = 0;
  table = document.getElementById('myTable');
  rows = table.rows;
  status = rows[n].getElementsByTagName("TD")[3].innerHTML;
  LuftKval = rows[n].getElementsByTagName("TD")[4].innerHTML;    //(id + 'luft').className)
  boks = document.getElementById(id + 'K');
  boks.getElementsByTagName('td')[1].innerHTML = status;
  boks.getElementsByTagName('td')[3].innerHTML = LuftKval;
  if (status == 'Ledig') {
    if (LuftKval == 'Hoy') {
      boks.style.backgroundColor = '#57BB3E';
    }
    else if (LuftKval == 'Middels') {
      boks.style.backgroundColor = '#FFBB00';
    }
    else if (LuftKval == 'Lav') {
      boks.style.backgroundColor = '#FF7440';
    }
  }
}

function statusFarge2() {
  for (var i = 0; i < 5; i++) {
    oppdatereKartDel(i + 111, i + 1);
  }
  for (var i = 0; i < 9; i++) {
    oppdatereKartDel(i + 209, i + 6);
  }
}

//

function hover(etasje1, etasje2) {
  var x, y = 0;
  x = document.getElementById(etasje1);
  y = document.getElementById(etasje2);
  x.style.width = '38%';
  y.style.width = '20%';
}

// Etasje utvider seg onmouseover
function hoverNot() {
  var x, y = 0;
  x = document.getElementById('etasje1');
  y = document.getElementById('etasje2');
  x.style.width = '28%';
  x.style.transition = '0.3s';
  y.style.width = '30%';
  y.style.transition = '0.3s';
  y.style.height = '100%';
  x.style.height = '100%';
}

function myFunction(x) {
  if (x.matches) { // If media query matches
    document.getElementById("romnummer").innerHTML = "Romnr.";
    document.getElementById("luftkvalitet").innerHTML = "Luftkval.";
  } else {
    document.getElementById("romnummer").innerHTML = "Romnummer";
    document.getElementById("luftkvalitet").innerHTML = "Luftkvalitet";
  }
}

var x = window.matchMedia("(max-width: 700px)");
myFunction(x); // Call listener function at run time
x.addListener(myFunction); // Attach listener function on state changes
statusFarge2();
luftStatus();

//easteregg2
