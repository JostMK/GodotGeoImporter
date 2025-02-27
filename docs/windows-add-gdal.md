# Adding GDAL Submodule on Windows

## Enable long paths in Windows 10

```powershell
New-ItemProperty -Path "HKLM:\SYSTEM\CurrentControlSet\Control\FileSystem" -Name "LongPathsEnabled" -Value 1 -PropertyType DWORD -Force
```
(See: https://learn.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=powershell)

## Enable long paths in Git 

```
git config --global core.longpaths true
```
(See: https://github.com/desktop/desktop/issues/8023#issuecomment-515115353)

## Adding Submodule with HEAD at specific tag

```
git add submodule https://github.com/OSGeo/gdal.git extern/gdal
cd extern/gdal
git checkout tags/<TAG_NAME>
```
