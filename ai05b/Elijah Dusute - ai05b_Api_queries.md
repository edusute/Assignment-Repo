# API Query Building Assignment
---

## USGS Earthquake Queries

### Query 1: [Describe what you're searching for]
**URL:**
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&starttime=2025-5-01&endtime=2025-5-31&limit=3
```

**Parameters used:**
- `format`: The format put it into a JSON file
- `parameter2`: The startdate parameter filters dates after may 1st 2025
- `parameter3`: The enddate parameter filters dates before may 31st 2025

**Result:** I got 3 earthquakes back from the link all taking place in May of 2025

---

### Query 2: [Describe what you're searching for]
**URL:**
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&minmagnitude=0.1&maxmagnitude=1&limit=10
```

**Parameters used:**
- `format`: Put it into a JSON file type
- `parameter2`: sorted the minimum magnitude to .1
- `parameter3`: sorted the maximum magnitude to 1

**Result:** got back 10 earthquakes that range from the smallest on being .67 and the largest one being .79

---

### Query 3: [Describe what you're searching for]
**URL:**
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&orderby=magnitude&limit=10
```

**Parameters used:**
- `format`: Json file type
- `parameter2`: sorts from the largest magnitudes to the smallest magnitudes
- `parameter3`: Limits the sort to 10 results

**Result:** [Brief description of what JSON data you got back]

---

## Open Library Queries

### Query 4: [Describe what you're searching for]
**URL:**
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&minlatitude=-30&maxlatitude=50&limit=10
```

**Parameters used:**
- `parameter1`: sorts from latitudes greater than -30
- `parameter2`: sorts by latitutes less than 50

**Result:** 10 results between latutdes -30 and 50


### Query 5: [Describe what you're searching for]
**URL:**
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&minlongitude=-130&maxlongitude=70&limit=10
```

**Parameters used:**
- `parameter1`: sorts from longitudes greater than -130
- `parameter2`: sorts by longitutes less than 70

**Result:** 10 results between longitudes -130 and 70

### Query 6: [Describe what you're searching for]
**URL:**
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&minlongitude=30&maxlatitude=60&limit=10
```

**Parameters used:**
- `parameter1`: sorts from longitudes greater than 30
- `parameter2`: sorts by latitutes less than 60

**Result:** 10 results greater than 30 longitude and less than 60 latitude