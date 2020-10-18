## Dateien für Make-Artikel

- `blob_ulab2_c_code` enthält den C-code, der das User-Modul von [`ulab`](https://github.com/v923z/micropython-ulab) um eine Funktion zum Detektieren von "Blob" in Bildern erweitert.
- `mpy_code` enthält das MicroPython-Beispielskript (Listing 1, `test_amg8833.py`) inklusive der notwendigen Treiber für den AMG8833 Wärmebildsensor.
- In `ulab_user_example` befindet sich der C-Code, der die Beispielfunktion (Listing 2) zu `ulab` hinzufügt.
- `amg8833_playground.ipyb` ist ein iPython-Notebook, dass den Zugriff auf den mit einem Mikrocontroller verbundenen AMG8833-Sensor mittels `pyboard.py` demonstriert (BETA).
- `front_pygame.py` implementiert Funktionen für eine einfache graphische Benutzeroberfläche und wird von `test_amg8833_gui.py` benötigt.
- `pyboard.py` erlaubt das Ausführen von MicroPython-Code auf einem Mikrocontroller, der über USB mit einem PC verbunden ist. Die Datei gehört zur MicroPython-Distribution, siehe [hier](https://github.com/micropython/micropython/blob/master/tools/pyboard.py).
- `test_amg8833_gui.py` liest Wärmebilder von einem über USB verbundenen Mikrocontroller und zeigt sie ein einer einfachen GUI an. Mittels der Tasten `1`, `2` und `3` kann zwischen den verschiedenen Implementierungen des Blob-Algorithmus (nur MicroPython, MicroPython mit `ulab`-Unterstützung und Erweiterung von `ulab`) gewechselt werden. Die Taste `s` schaltet zwischen normalem und geglättetem Wärmebild hin und her. 
