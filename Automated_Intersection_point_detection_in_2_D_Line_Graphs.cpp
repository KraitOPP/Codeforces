from PIL import Image
import sys

THRESHOLD = 128
MIN_NEIGHBORS = 3
AXIS_MARGIN = 0.1


def load_gray(path):
    img = Image.open(path)
    return img.convert('L')


def to_binary(img):
    return img.point(lambda p: 1 if p < THRESHOLD else 0)


def neighbors(x, y, w, h):
    for dx in (-1, 0, 1):
        for dy in (-1, 0, 1):
            if dx or dy:
                nx, ny = x + dx, y + dy
                if 0 <= nx < w and 0 <= ny < h:
                    yield nx, ny


def find_junctions(binary):
    pix = binary.load()
    w, h = binary.size
    points = set()
    for y in range(h):
        for x in range(w):
            if pix[x, y]:
                count = sum(pix[nx, ny] for nx, ny in neighbors(x, y, w, h))
                if count >= MIN_NEIGHBORS:
                    points.add((x, y))
    return points, w, h


def cluster(points, w, h):
    visited = set()
    groups = []
    for pt in points:
        if pt in visited:
            continue
        stack = [pt]
        group = []
        while stack:
            x, y = stack.pop()
            if (x, y) in visited:
                continue
            visited.add((x, y))
            group.append((x, y))
            for n in neighbors(x, y, w, h):
                if n in points and n not in visited:
                    stack.append(n)
        groups.append(group)
    return groups


def count_intersections(path):
    gray = load_gray(path)
    binary = to_binary(gray)
    points, w, h = find_junctions(binary)
    groups = cluster(points, w, h)
    margin_x = int(w * AXIS_MARGIN)
    margin_y = int(h * AXIS_MARGIN)
    count = 0
    for grp in groups:
        xs = [x for x, _ in grp]
        ys = [y for _, y in grp]
        cx, cy = sum(xs) / len(xs), sum(ys) / len(ys)
        if cy > h - margin_y or cx < margin_x:
            continue
        count += 1
    return count


def main():
    fname = sys.argv[1] if len(sys.argv) > 1 else input().strip()
    result = count_intersections(fname)
    print(result)

if _name_ == '_main_':
    main()