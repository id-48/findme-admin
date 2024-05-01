import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:find_me_admin/utils/Extensions/colors.dart';
import 'package:find_me_admin/widget/custom_image_show.dart';

class SelectedImageViewer extends StatelessWidget {
  final List<Uint8List> res;
  final void Function(void Function()) setState;

  const SelectedImageViewer(
      {Key? key, required this.res, required this.setState})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      child: GridView.builder(
          physics: const NeverScrollableScrollPhysics(),
          gridDelegate: const SliverGridDelegateWithMaxCrossAxisExtent(
              maxCrossAxisExtent: 100,
              mainAxisExtent: 100,
              childAspectRatio: 3 / 2,
              crossAxisSpacing: 8,
              mainAxisSpacing: 8),
          shrinkWrap: true,
          itemCount: res.length,
          itemBuilder: (BuildContext ctx, index) {
            return Stack(
              clipBehavior: Clip.none,
              children: [
                Container(
                  height: 100,
                  width: 110,
                  padding: const EdgeInsets.only(right: 8.0, top: 10),
                  child: ClipRRect(
                    borderRadius: BorderRadius.circular(15),
                    child: AppImage(res[index]),
                    // child: Image.memory(res[index],
                    //     height: 100,
                    //     width: 100,
                    //     fit: BoxFit.cover,
                    //     alignment: Alignment.center),
                  ),
                ),
                Positioned(
                  top: 0,
                  right: 0,
                  child: GestureDetector(
                    onTap: () {
                      setState(() {});
                      res.removeAt(index);
                      // res.value.
                    },
                    child: Container(
                      decoration: const BoxDecoration(
                          shape: BoxShape.circle, color: Colors.red),
                      child: const Icon(
                        Icons.close,
                        color: white,
                        size: 25,
                      ),
                    ),
                  ),
                ),
              ],
            );
          }),
    );
  }
}
