import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/models/jackbase/add_jackbase/req_jackbase.dart';
import 'package:find_me_admin/models/jackbase/get_jackbase/res_jackbase.dart';
import 'package:find_me_admin/models/jackbase/update_jackbase/req_update_jackbase.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/add_jackbase_screen.dart';
import 'package:find_me_admin/utils/Extensions/string_extensions.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';

import '../../main.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/text_styles.dart';

class AddJackBaseDialog extends StatefulWidget {
  static String tag = '/AddJackBaseDialog';

  final JackBase? jackBaseData;
  final Function()? onUpdate;

  AddJackBaseDialog({this.onUpdate, this.jackBaseData});

  @override
  State<AddJackBaseDialog> createState() => _AddJackBaseDialogState();
}

class _AddJackBaseDialogState extends State<AddJackBaseDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  TextEditingController jackBaseController = TextEditingController();

  bool isUpdate = false;
  final borderRadius = BorderRadius.all(Radius.circular(9.0));

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    isUpdate = widget.jackBaseData != null;

    if (isUpdate) {
      jackBaseController.text = widget.jackBaseData!.jackBase.validate();
    }
  }

  AddJackBaseApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      String jackBase = jackBaseController.text.trim();

      ReqJackbase jackbaseData = await ReqJackbase(
          jackBase: jackBase
      );

      await addJackBase(req: jackbaseData).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");

          Navigator.pushNamed(context, AddJackBaseScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  UpdateJackBaseApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      String jackBase = jackBaseController.text.trim();


      ReqUpdateJackbase updateJackbaseData = ReqUpdateJackbase(
        jackBaseId: widget.jackBaseData!.id,
        jackBase: jackBase,

      );

      await updateJackBase(req: updateJackbaseData).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");
          Navigator.pushNamed(context, AddJackBaseScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }


  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      actionsPadding: EdgeInsets.only(right: 16, bottom: 16),
      title: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text("Add Jack & Base Details",
              style: boldTextStyle(color: primaryColor, size: 20)),
          IconButton(
            icon: Icon(Icons.close),
            padding: EdgeInsets.zero,
            onPressed: () {
              Navigator.pop(context, false);
            },
          ),
        ],
      ),
      content: Observer(builder: (context) {
        return SingleChildScrollView(
          child: Stack(
            children: [
              Visibility(
                visible: !appStore.isLoading,
                child: Form(
                  key: _formKey,
                  child: SizedBox(
                    width: ResponsiveWidget.isMediumScreen(context)
                        ? getBodyWidth(context)
                        : (getBodyWidth(context) - 48) * 0.4,
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Text("Jack and Base", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: jackBaseController,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),

                      ],
                    ),
                  ),
                ),
              ),
              Visibility(visible: appStore.isLoading, child: loaderWidget()),
            ],
          ),
        );
      }),
      actions: <Widget>[
        dialogSecondaryButton("Cancel", () {
          Navigator.pop(context, false);
        }),
        SizedBox(width: 4),
        dialogPrimaryButton(isUpdate ? "Update" : "Add", () {
          isUpdate ? UpdateJackBaseApi() : AddJackBaseApi();
        }),
      ],
    );
  }
}
