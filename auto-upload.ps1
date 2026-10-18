while ($true) {
    Start-Sleep -Seconds 5

    git add -A

    if ($LASTEXITCODE -ne 0) {
        Write-Host "Git add failed."
        continue
    }

    git diff --cached --quiet

    if ($LASTEXITCODE -eq 0) {
        continue
    }

    if ($LASTEXITCODE -ne 1) {
        Write-Host "Could not check staged changes."
        continue
    }

    git commit -m "Auto-upload: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"

    if ($LASTEXITCODE -ne 0) {
        Write-Host "Commit failed. Check the error above."
        continue
    }

    git push origin HEAD

    if ($LASTEXITCODE -eq 0) {
        Write-Host "Successfully uploaded to GitHub!"
    } else {
        Write-Host "Upload failed. Check the error above."
    }
}