# CI and decomp.dev

The [Build workflow](../.github/workflows/build.yml) builds the game on every push, checks that every module still matches and
uploads the objdiff progress report as a `usa_report` artifact. [decomp.dev](https://decomp.dev) reads these artifacts to draw
the progress map, the badges and the history of the project.

The workflow needs the files extracted from the ROM, which can't be published. They live in a **private** Docker image on
GitHub Container Registry that only this repository's workflows can pull.

## 1. Push the private build image

1. Create a [classic personal access token](https://github.com/settings/tokens/new?scopes=write:packages&description=bis-decomp-ghcr)
   with the `write:packages` scope.
2. Log in to the registry (paste the token when asked):
   ```shell
   docker login ghcr.io -u istornz
   ```
3. Build and push the image (from the repository root, on the host):
   ```shell
   ./tools/ci/push_build_image.sh
   ```

Rerun step 3 only if `extract/` changes (new `dsd` version, other game version).

## 2. Give the repository access to the image

On GitHub: **profile → Packages → `bowsers-inside-story-decomp-build` → Package settings**:

- **Danger Zone → Change visibility**: it must be **Private** (the default for a new package). Never make it public.
- **Manage Actions access → Add repository**: `bowsers-inside-story-decomp`, role **Read**.

Then run the workflow (**Actions → Build → Run workflow**, or push a commit). The run must succeed and show a `usa_report`
artifact.

## 3. Add the project to decomp.dev

1. Sign in on [decomp.dev](https://decomp.dev) with GitHub (admin rights on the repository are required, the repository must
   be public).
2. **Manage → Add New**: select the repository, game name `Mario & Luigi: Bowser's Inside Story`, platform Nintendo DS.
3. In the project settings, select the `Build` workflow and use **Refresh** to fetch the existing reports.

## Badges and progress map

Once the project is on decomp.dev:

```markdown
[![Code](https://decomp.dev/istornz/bowsers-inside-story-decomp/usa.svg?mode=shield&measure=code&label=Code)](https://decomp.dev/istornz/bowsers-inside-story-decomp)

[<img src="https://decomp.dev/istornz/bowsers-inside-story-decomp.svg?w=512&h=256" width="512" height="256" alt="Progress map">](https://decomp.dev/istornz/bowsers-inside-story-decomp)
```

Each rectangle of the map is a source file (or a not yet decompiled part of a module), sized by its code size and colored by
how much of it matches.
