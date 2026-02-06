# AI05b: API URL Building Assignment
**Building API Queries Manually**

**AI/ML Course | Medina County Career Center**

---

## Overview

In this assignment, you'll learn to **construct API URLs by hand** and test them directly in your web browser. 

**No Python required -** You'll build URLs as plain text and paste them into your browser's address bar.

---

## Assignment Requirements

✅ **Build 3 different API queries** (URLs)  
✅ **Test each URL** in your browser to confirm it returns JSON data  
✅ **Document your queries** in the template file provided  
✅ **Submit to GitHub** with filename: `lastname_api_queries.md`

---

## The Two APIs You'll Use

### 1. USGS Earthquake API
**Purpose:** Real-time earthquake data from the US Geological Survey

**Base URL:**
```
https://earthquake.usgs.gov/fdsnws/event/1/query
```

### 2. Open Library API
**Purpose:** Search for books and authors

**Base URL:**
```
https://openlibrary.org/search.json
```

---

## Part 1: Understanding URL Structure

Every API URL has this basic structure:

```
https://domain.com/path?parameter1=value1&parameter2=value2
```

**Breaking it down:**

| Component | Description | Example |
|-----------|-------------|---------|
| `https://` | Protocol (secure web) | Always `https://` |
| `domain.com` | API server address | `earthquake.usgs.gov` |
| `/path` | Specific endpoint | `/fdsnws/event/1/query` |
| `?` | Start of parameters | Marks where parameters begin |
| `parameter=value` | Query filters | `minmagnitude=5.0` |
| `&` | Parameter separator | Joins multiple parameters |

**Example:**
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&minmagnitude=6.0&limit=5
```

This URL says:
- Use the USGS earthquake API
- Return data in GeoJSON format
- Only earthquakes magnitude 6.0+
- Limit results to 5

---

## Part 2: USGS Earthquake API Documentation

### Base URL
```
https://earthquake.usgs.gov/fdsnws/event/1/query
```

### Available Parameters

| Parameter | Type | Description | Example Values |
|-----------|------|-------------|----------------|
| `format` | string | Output format | `geojson`, `xml`, `csv` |
| `minmagnitude` | number | Minimum magnitude | `2.5`, `5.0`, `7.0` |
| `maxmagnitude` | number | Maximum magnitude | `3.0`, `6.0`, `8.0` |
| `starttime` | date | Start date (YYYY-MM-DD) | `2024-01-01` |
| `endtime` | date | End date (YYYY-MM-DD) | `2024-12-31` |
| `limit` | integer | Max results (1-20000) | `10`, `50`, `100` |
| `orderby` | string | Sort order | `time`, `magnitude` |
| `minlatitude` | number | Southern boundary | `30.0`, `-90.0` |
| `maxlatitude` | number | Northern boundary | `50.0`, `90.0` |
| `minlongitude` | number | Western boundary | `-130.0` |
| `maxlongitude` | number | Eastern boundary | `-65.0` |

**Note:** `format=geojson` is recommended - it's the most readable in browsers.

### USGS Example Queries

#### Example 1: Recent earthquakes worldwide (magnitude 5.0+)
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&minmagnitude=5.0&limit=10
```

#### Example 2: Earthquakes in California date range
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&starttime=2024-01-01&endtime=2024-12-31&minlatitude=32&maxlatitude=42&minlongitude=-124&maxlongitude=-114&limit=20
```

#### Example 3: Large earthquakes sorted by magnitude
```
https://earthquake.usgs.gov/fdsnws/event/1/query?format=geojson&minmagnitude=6.0&orderby=magnitude&limit=15
```

---

## Part 3: Open Library API Documentation

### Base URL
```
https://openlibrary.org/search.json
```

### Available Parameters

| Parameter | Type | Description | Example Values |
|-----------|------|-------------|----------------|
| `title` | string | Search book titles | `python`, `harry+potter` |
| `author` | string | Search by author | `tolkien`, `j+k+rowling` |
| `q` | string | General search (all fields) | `artificial+intelligence` |
| `limit` | integer | Max results (1-100) | `5`, `10`, `20` |
| `fields` | string | Specific fields to return | `title,author_name,first_publish_year` |
| `language` | string | Filter by language | `eng`, `spa`, `fre` |
| `subject` | string | Search by subject/genre | `science+fiction`, `history` |

**Note:** Use `+` for spaces in search terms (e.g., `harry+potter`)

### Open Library Example Queries

#### Example 1: Search for Python programming books
```
https://openlibrary.org/search.json?title=python&limit=5
```

#### Example 2: Books by Stephen King
```
https://openlibrary.org/search.json?author=stephen+king&limit=10
```

#### Example 3: Science fiction books with specific fields
```
https://openlibrary.org/search.json?subject=science+fiction&limit=5&fields=title,author_name,first_publish_year
```

#### Example 4: General search for AI/ML topics
```
https://openlibrary.org/search.json?q=machine+learning&limit=8
```

---

## Part 4: Your Assignment Tasks

### Task 1: Build 3 USGS Earthquake Queries

Create three different earthquake queries. Each should use **different parameters** to answer a specific question.

**Ideas for queries:**
- All earthquakes above magnitude 7.0 in the past year
- Earthquakes in a specific geographic region (pick coordinates)
- Recent small earthquakes (magnitude 2.0-3.0)
- Earthquakes sorted by time vs. magnitude
- Earthquakes from a specific date range

**Requirements:**
- Use `format=geojson` (makes it readable)
- Each query must use at least 3 different parameters
- Document what each query is looking for

---

### Task 2: Build 3 Open Library Queries

Create two different book search queries.

**Ideas for queries:**
- Books about a specific topic (space, cooking, Python, etc.)
- Books by your favorite author
- Books in a specific genre with year filter
- Search limited to specific fields
- Compare results for different search terms

**Requirements:**
- Each query must use at least 2 different parameters
- Document what you're searching for

---

## Part 5: Testing Your Queries

### How to Test:

1. **Copy your URL** (the entire thing!)
2. **Open a new browser tab**
3. **Paste the URL** into the address bar
4. **Press Enter**
5. **Verify you see JSON data** (looks like nested brackets and key-value pairs)

### What Your Responses Should Look Like (sample only):

**✅ Good response (USGS):**
```json
{
  "type": "FeatureCollection",
  "metadata": {
    "generated": 1738363200000,
    "count": 5
  },
  "features": [
    {
      "type": "Feature",
      "properties": {
        "mag": 5.2,
        "place": "Pacific Ocean",
        ...
```

**✅ Good response (Open Library):**
```json
{
  "numFound": 234,
  "docs": [
    {
      "title": "Learning Python",
      "author_name": ["Mark Lutz"],
      ...
```

**❌ Error response:**
```json
{
  "error": "invalid parameter"
}
```

If you get an error:
- Check your spelling
- Verify parameter names match documentation
- Make sure values are in the correct format
- Check for typos in the base URL

---
## Submission Instructions

1. **Submit** your markdown file: `api_queries.md`to AI / ML repository and share link in Google Classroom.
2. **Test all URLs** - make sure your queries work in your browser!

## Resources

- **USGS Full Documentation:** https://earthquake.usgs.gov/fdsnws/event/1/
- **Open Library API Docs:** https://openlibrary.org/dev/docs/api/search


